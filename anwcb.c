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

#include <stdio.h>

#include "anwcb.h"
#include "mainMenu.h"

#define DEFAULT_PAY_RATE   0.0
#define DEFAULT_WORK_HOURS 0.0
#define DEFAULT_OVERTIME   0.0

void initialize(void) {
	payRate = DEFAULT_PAY_RATE;
	hoursWorked = DEFAULT_WORK_HOURS;
	overtimeHours = DEFAULT_OVERTIME;

	printf("Alberta Net Wage Calculator (Basic) (C) 2016 Author: Elliott Sobek.\n"
		"This program comes with ABSOLUTELY NO WARRANTY.\nThis is free "
		"software, and you are welcome to redistribute it under certain "
		"conditions.\n");
}

int main(void) {
	initialize();
	mainMenu();
	return 0;
}
