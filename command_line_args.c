/**
 * Example of command line parsing using 'getopt'.
 **/
#include "dbg.h"     // debugging library, defined in dbg.h
#include <stdio.h>   // standard libraries
#include <stdlib.h>
#include <unistd.h>

void usage() {
  printf("Usage: router [-c config] [-p port] [-t ttl] [-e period] [-s split-horizon]\n");
}


/**
 * Main entry point.
 *  
 *  Usage: router [-c config] [-p port] [-t ttl] [-e period] [-s split-horizeon] 
 *
 * defaults:
 *  port   = DEFAULTPORT
 *  ttl    = 90 (seconds)
 *  period = 30 (seconds)
 *  split_horizon = 0 (false)
 *
 * @return 0 on success, 1 on failure
 **/
int main(int argc, char *argv[]) {
  char *config;
  int c;
  int found_config = 0;

  int ttl = 90;
  int period = 30;
  int portno = 53818;
  int split_horizon = 0;

  // Colon means there is an extra argument that will be bound
  // to 'optarg' when that argument is found.
  //
  // eg. "c:p:" allows these kind of arguments:
  //       -c foo -p bar
  //     Then 'optarg' will be "foo" if we're parsing the '-c'
  //     argument (ie. in the "case 'c'" case below).
  while ((c = getopt(argc, argv, "c:p:t:e:s:")) != -1) {
    switch(c) {
      case 'c':
        config = optarg;
        found_config = 1;
        continue;
      case 'p':
        portno = atoi(optarg);
        continue;
      case 'e':
        period = atoi(optarg);
        continue;
      case 't':
        ttl = atoi(optarg);
        continue;
      case 's':
        split_horizon = atoi(optarg);
        continue;
      case '?':
        usage();
        continue;
    }
  }

  check(found_config, "Must provide configuration file with -c argument.");

  printf("split_horizon = %i\n", split_horizon);
  printf("portno = %i\n", portno);
  printf("ttl = %i\n", ttl);
  printf("period = %i\n", period);
  printf("config = %s\n", config);

  debug("Done");

  return 0;

error:
  return 1;
}
