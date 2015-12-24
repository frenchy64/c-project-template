#include "minunit.h"
#include "dbg.h"
#include "util.h"
#include <unistd.h>

/**
 * Tests for subtraction.
 **/
char *check_subtraction() {
  mu_assert(1 - 1 == 0, "1 - 1 does not equal 0");

  mu_assert(54 - 12 == 42, "54 - 12 does not equal 42");

  return (char*) NULL;
}

/**
 * Tests for addition.
 **/
char *check_addition() {
  mu_assert(1 + 1 == 2, "1 + 1 does not equal 2");

  mu_assert(12 + 30 == 42, "12 + 30 does not equal 42");

  return (char*) NULL;
}

/**
 * Main test suite.
 **/
char *all_tests() {
  mu_suite_start();

  // from dbg.h
  debug("Starting the test suite... ");

  mu_run_test(check_addition);
  mu_run_test(check_subtraction);

  debug("Finished the test suite.");

  return (char*)NULL;
}

/**
 * Runs the test suite.
 **/
RUN_TESTS(all_tests);
