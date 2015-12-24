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
