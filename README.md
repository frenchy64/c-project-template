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

## Running the example projects

The first example is `command_line_args.c`, which can be built by `make compile`,
or `make`.

As before, run 

```
valgrind ./project
```

to run the program.

Notice there is a bunch of valgrind logging, a single error (written `[ERROR]`)
and then the program ends.

Inspecting the `command_line_args.c` source, you'll notice that the `-c`
command line option must be provided.
This is enforced by a call to `check`, which jumps to the `error:` label
(labels are specified with a `:` suffix, so it's really called `error`)
if the first argument is zero, and otherwise continues normal program
  execution.

For example, `check(0, "Bad")` will jump to `error:` with the message
`Bad`, but `check(1, "Bad")` will just execute the next line like normal.
The idea is that `error:` will signal an error by returning a particular
value (returning 0 for success, -1 for failure is often good).

Let's provide the `-c` argument.

```
valgrind ./project -c foo_bar
```

Now something more interesting happens. The `printf` calls are now being run.
We also see a `DEBUG` call.
This is the `debug` macro being called; notice the file name and line number
is specified next to it, you should track down this coordinate and try
changing the `debug` call.

## About the test framework

The unit testing framework is defined in `minunit.h`. See the source
for more links to more information.

The file `tests.c` has an example of the testing framework in action.

`make test` will run the tests in the file. You should try and make
some of the tests fail and see what it looks like.
