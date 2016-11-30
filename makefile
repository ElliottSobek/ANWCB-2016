CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -O3 -std=c11

.PHONY: all clean

all: anwcb

anwcb: anwcb.o mainMenu.o shared.o
	$(CC) $(CFLAGS) $^ -o ANWCB

anwcb.o: anwcb.c

mainMenu.o: mainMenu.c

shared.o: shared.c

clean:
	rm *.o
