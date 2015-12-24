# C project template

This is a template for C projects using Valgrind, a small test
suite framework and a small debugging framework.

## How to build

See `Makefile` for the build scripts.

To build the command line example, simply run `make` or `make compile`
at the command line in the current directory.

By default, this will generate an executable called whatever `NAME`
is bound to in `Makefile` (by default, `project`).
To then run the program with Valgrind (recommended!), run

```
valgrind ./project
```

in the project directory.

To compile and run the test suite, run `make test`.

## About the test framework

The unit testing framework is defined in `minunit.h`. See the source
for more links to more information.

The file `tests.c` has an example of the testing framework in action.

`make test` will run the tests in the file. You should try and make
some of the tests fail and see what it looks like.
