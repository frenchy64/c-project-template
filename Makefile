# Hashes start line comments in Makefiles.

# Here we define a few variables that we use later.
NAME=project
TESTS=tests
CC=gcc

# These are various C compiler flags.
CFLAGS=-Wall -lrt -lm #-DNDEBUG
# Flags:
#  -Wall enable all warnings
#  -lrt  timing library
#  -lm   math library
#  -DNDEBUG disables debugging, uncomment if needed above

# `make`
# When calling `make`, the first argument we pass determines what happens
# next. The default (`make`) just matches the first event, `all`, defined
# below. All it does is call the `compile` event, so `make` is the same
# as `make compile`.
all: compile

# `make compile`
# Notice we can use variables with the $(VAR_NAME) syntax.
# We insert the compiler flags and the name of the C compiler via variables.
compile:
	$(CC) command_line_args.c util.c -o command_line_args $(CFLAGS)

# `make clean`
# Deletes the file called NAME (defined above).
clean:
	rm $(NAME)

# `make test`
# Compile and run the test suite under Valgrind.
test:
	$(CC) util.c tests.c -o $(TESTS) $(CFLAGS)
	valgrind --track-origins=yes ./$(TESTS)
