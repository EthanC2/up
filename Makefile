ERROR_FLAGS=-Wall -Wextra -Werror
DEBUG_FLAGS=-g3 -ggdb
RELEASE_FLAGS=-O3

up: main.o
	gcc ${ERROR_FLAGS} ${DEBUG_FLAGS} main.o -o up

main.o: main.c
	gcc -c ${ERROR_FLAGS} ${DEBUG_FLAGS} main.c

clean:
	rm up main.o
