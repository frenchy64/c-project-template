// From "C Programming the hard way", Zed Shaw
// Use the -DNDEBUG flag to disable debugging.
#ifndef __dbg_h__
#define __dbg_h__

#include <stdio.h>
#include <errno.h>
#include <string.h>
//#include <pthread.h>  include this if using alternative `debug` implementation

/** 
  // notice you don't need the \n
  debug("I have Brown Hair.");

  // passing in arguments like printf
  debug("I am %d years old.", 37);
**/
#ifdef NDEBUG
#define debug(M, ...)
#else
// if you need to know which thread you're executing on, comment out the next line and uncomment the 2nd line after this. Also uncomment the pthread.h include above.
#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
//#define debug(M, ...) fprintf(stderr, "DEBUG %s:%d: [Thread: %i] " M "\n", __FILE__, __LINE__, (int)pthread_self(), ##__VA_ARGS__)
#endif

#if defined(CNGSTDEBUG) || !defined(NDEBUG)
#define cngst_debug(M, ...) fprintf(stderr, "[CNGST_DEBUG] (%s:%d): " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define cngst_debug(M, ...)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(stderr, "[ERROR] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(stderr, "[WARN] (%s:%d: errno: %s) " M "\n", __FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(stderr, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if(!(A)) { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define sentinel(M, ...)  { log_err(M, ##__VA_ARGS__); errno=0; goto error; }

#define check_mem(A) check((A), "Out of memory.")

#define check_debug(A, M, ...) if(!(A)) { debug(M, ##__VA_ARGS__); errno=0; goto error; }

#define print_both(F, ...) { fprintf(stdout, ##__VA_ARGS__); if(F) { fprintf(F, ##__VA_ARGS__); }; }

#endif
