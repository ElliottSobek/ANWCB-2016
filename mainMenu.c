/*
 * Alberta Net Wage Calculator (Basic)
 * Copyright (C) 2016  Author: Elliott Sobek
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#if _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>

#include "anwcb.h"
#include "shared.h"

static short getMainMenuInput(void) {
	printf("1. Calculate net income\n"
		   "2. Set amount of hours (%.2f)\n"
		   "3. Set pay rate (%.2f)\n"
		   "4. Set amount of overtime hours (%.2f)\n"
		   "0. Exit\n\n", hoursWorked, payRate, overtimeHours);
	short input;
	printf("Enter a menu option: ");
	scanf("%hi", &input);
	return input;
}

static double calculateGrossIncome(void) {
	const double standardIncome = payRate * hoursWorked,
				 overtimeIncome = standardIncome * 1.5;

	return standardIncome + overtimeIncome;
}

static double calculateDeductions(const double grossIncome) {
	const double totalDeductionAmount = EI + CPP;

	return grossIncome * totalDeductionAmount;
}

static double calculateNetIncome(void) {
	const double grossIncome = calculateGrossIncome();

	return grossIncome - calculateDeductions(grossIncome);
}

static void setAmountOfHours(void) {
	double amountOfHours;
	printf("\nEnter an amount of hours between 0 and 8760 inclusive. 0 To go back: ");
	scanf("%lf", &amountOfHours);
	while (!isValidBounds(amountOfHours, 0, 8760)) {
		purgeBuffer();
		printf("\nEntered amount of hours not between 1 and 8760 inclusive. 0 To go back: ");
		scanf("%lf", &amountOfHours);
	}
	if (0.0 == amountOfHours)
		return;
	hoursWorked = amountOfHours;
}

static void setPayRate(void) {
	double rateOfPay;
	printf("\nEnter a pay rate between 0 and 1,000 inclusive. 0 To go back: ");
	scanf("%lf", &rateOfPay);
	while (!isValidBounds(rateOfPay, 0, 1000)) {
		purgeBuffer();
		printf("\nEntered pay rate not between 1 and 1,000 inclusive. 0 To go back: ");
		scanf("%lf", &rateOfPay);
	}
	if (0.0 == rateOfPay)
		return;
	payRate = rateOfPay;
}

static void setOverTimeHours(void) {
	double numberOfOvertimeHours;
	printf("\nEnter an amount of overtime hours between 0 and 3328 inclusive. 0 To go back: ");
	scanf("%lf", &numberOfOvertimeHours);
	while (!isValidBounds(numberOfOvertimeHours, 0, 3328)) {
		purgeBuffer();
		printf("\nEnter an amount of overtime hours not between 0 and 3328 inclusive. 0 To go back: ");
		scanf("%lf", &numberOfOvertimeHours);
	}
	if (0.0 == numberOfOvertimeHours)
		return;
	overtimeHours = numberOfOvertimeHours;
}

void mainMenu(void) {
	short input = getMainMenuInput();

	while (1) {
		while (!isValidBounds(input, 0, 4)) {
			purgeBuffer();
			printf("\nNot a menu option\n");
			input = getMainMenuInput();
		}
		switch (input) {
		case 1:
			printf("\nNet income: %.2lf\n", calculateNetIncome());
			input = getMainMenuInput();
			break;
		case 2:
			setAmountOfHours();
			input = getMainMenuInput();
			break;
		case 3:
			setPayRate();
			input = getMainMenuInput();
			break;
		case 4:
			setOverTimeHours();
			input = getMainMenuInput();
			break;
		case 0:
			exit(EXIT_SUCCESS);
		}
	}
}
