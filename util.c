#include "dbg.h"
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <arpa/inet.h>
#include <time.h>


// implementation based on http://stackoverflow.com/questions/3756323/getting-the-current-time-in-milliseconds
/**
 * Current time in milliseconds
 **/
long current_ms() {
  struct timespec spec;

  clock_gettime(CLOCK_REALTIME, &spec);

  return spec.tv_sec * 1000 + round(spec.tv_nsec / 1.0e6); // Convert nanoseconds to milliseconds
}

/**
 * Modulo that correctly wraps around if a is zero.
 **/
int mod(int a, int b) {
  int c = a % b;
  return (c < 0 ? c+b : c);
}

// implementation based on http://www.geekpage.jp/en/programming/linux-network/get-ipaddr.php
/**
 * Populate allocated string with the IP address of the outward-facing IP address
 * of this machine.
 *
 * If local == 1, then always return the loopback interface.
 **/
int my_ip(char *ip, int local) {
  int iret;
  int fd;
  struct ifreq ifr;

  check((fd = socket(AF_INET, SOCK_DGRAM, 0)) != -1,
      "Failed to open socket");

  /* I want to get an IPv4 IP address */
  ifr.ifr_addr.sa_family = AF_INET;

  /* I want IP address attached to "em1" */
  strncpy(ifr.ifr_name, "em1", IFNAMSIZ-1);

  iret = ioctl(fd, SIOCGIFADDR, &ifr);

  close(fd);

  /* copy ip address into result, default to 127.0.0.1 on error  */
  if (iret == 0 && local == 0) {
    check(sprintf(ip, inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr)) >= 0,
        "Failed to copy ip");
  } else {
    check(sprintf(ip, "127.0.0.1"),
        "Failed to copy ip");
  }

  return 0;

error:
  close(fd);
  return -1;
}

/**
 * Sleep for ms milliseconds.
 * 
 * @ms milliseconds to sleep for
 *
 * @return 0 for normal return
 **/
int sleep_ms(long ms) {
  struct timespec t;
  t.tv_sec = 0;
  t.tv_nsec = ms * 1000000;

  nanosleep(&t, NULL);

  return 0;
}
