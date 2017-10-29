# Alberta Net Wage Calculator (Basic)
# Copyright (C) 2016  Author: Elliott Sobek
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

CC = gcc

CFLAGS = -Wall -Wextra -Wpedantic -O3 -std=c11 -Wno-unused-result

.PHONY: all clean

all: anwcb

anwcb: anwcb.o mainMenu.o shared.o
	$(CC) $(CFLAGS) $^ -o ANWCB

anwcb.o: anwcb.c

mainMenu.o: mainMenu.c

shared.o: shared.c

clean:
	rm *.o
