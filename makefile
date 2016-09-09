CC = gcc

CFLAGS = -Wall -std=c11

all: anwcb

anwcb: anwcb.o mainMenu.o shared.o
	$(CC) $(CFLAGS) pst.o mainMenu.o shared.o -o ANWCB

anwcb.o: anwcb.c
	$(CC) $(CFLAGS) pst.c -c

mainMenu.o: mainMenu.c
	$(CC) $(CFLAGS) mainMenu.c -c

shared.o: shared.c
	$(CC) $(CFLAGS) shared.c -c

.PHONY: clean
clean:
	rm *.o