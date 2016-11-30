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

#ifndef ANWCB_H
#define ANWCB_H

#include <stdbool.h>

#define EI  0.0188
#define CPP 0.0495

#define DEFAULT_PAY_RATE   0.0
#define DEFAULT_WORK_HOURS 0.0
#define DEFAULT_OVERTIME   0.0

/* Globals */
double payRate;
double hoursWorked;
double overtimeHours;

#endif /* End ANWCB_H */
