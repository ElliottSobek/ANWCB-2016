CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -03 -std=c11

.PHONY: all clean

all: anwcb

anwcb: anwcb.o mainMenu.o shared.o
	$(CC) $(CFLAGS) anwcb.o mainMenu.o shared.o -o ANWCB

anwcb.o: anwcb.c

mainMenu.o: mainMenu.c

shared.o: shared.c

clean:
	rm *.o
