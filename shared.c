/*
* Alberta Net Wage Calculator (Basic)
* Copyright (C) 2016  Author: Elliott Sobek
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "anwcb.h"

void purgeBuffer(void) {
	fseek(stdin, 0, SEEK_END);
}

bool isValidBounds(double input, short int lowerBound, int upperBound) {
	if ((input < lowerBound) || (input > upperBound)) {
		return false;
	}
	return true;
}