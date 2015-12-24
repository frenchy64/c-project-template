NAME=project
CC=gcc

CFLAGS=-Wall -lrt -lm #-DNDEBUG
# Flags:
#  -Wall enable all warnings
#  -lrt  timing library
#  -lm   math library
#  -DNDEBUG disables debugging, uncomment if needed above

all: compile

compile:
	$(CC) command_line_args.c util.c -o command_line_args $(CFLAGS)

clean:
	rm router

test:
	$(CC) util.c tests.c -o tests $(CFLAGS)
	valgrind --track-origins=yes ./tests
