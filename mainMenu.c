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

#if _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include "anwcb.h"

void mainMenu(void) {
	short int input;
	input = getMainMenuInput();
	while (1) {
		while (false == isValidBounds(input, 0, 4)) {
			purgeBuffer();
			printf("\nNot a menu option\n");
			input = getMainMenuInput();
		}
		switch (input) {
			case 1:
				printf("Done Calculate %lf\n", calculateNetIncome());
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

short int getMainMenuInput(void) {
	printf("\n1. Calculate\n2. Set amount of hours (%hi)\n3. Set pay rate (%.2f)"
		   "\n4. Set amount of overtime hours (%hi)\n0. Exit\n\n", hoursWorked, payRate, overtimeHours);
	short int input;
	printf("Enter a menu option: ");
	scanf("%hi", &input);
	return input;
}

void setAmountOfHours(void) {
	short int amountOfHours;
	printf("\nEnter an amount of hours between 0 and 8760 inclusive. 0. To go back: ");
	scanf("%hi", &amountOfHours);
	while (false == isValidBounds(amountOfHours, 0, 8760)) {
		purgeBuffer();
		printf("\nEntered amount of hours not between 1 and 8760 inclusive. 0. To go back: ");
		scanf("%hi", &amountOfHours);
	}
	if (amountOfHours == 0) {
		return;
	}
	hoursWorked = amountOfHours;
}

void setPayRate(void) {
	double rateOfPay;
	printf("\nEnter a pay rate between 0 and 1,000 inclusive. 0. To go back: ");
	scanf("%lf", &rateOfPay);
	while (false == isValidBounds(rateOfPay, 0, 1000)) {
		purgeBuffer();
		printf("\nEntered pay rate not between 1 and 1,000 inclusive. 0. To go back: ");
		scanf("%lf", &rateOfPay);
	}
	if (rateOfPay == 0) {
		return;
	}
	payRate = rateOfPay;
}

void setOverTimeHours(void) {
	short int numberOfOvertimeHours;
	printf("\nEnter an amount of overtime hours between 0 and 3328 inclusive. 0. To go back: ");
	scanf("%hi", &numberOfOvertimeHours);
	while (false == isValidBounds(numberOfOvertimeHours, 0, 3328)) {
		purgeBuffer();
		printf("\nEnter an amount of overtime hours not between 0 and 3328 inclusive. 0. To go back: ");
		scanf("%hi", &numberOfOvertimeHours);
	}
	if (numberOfOvertimeHours == 0) {
		return;
	}
	overtimeHours = numberOfOvertimeHours;
}

double calculateNetIncome(void) {
	double grossIncome = calculateGrossIncome();
	return grossIncome - calculateDeductions(grossIncome);
}

double calculateGrossIncome(void) {
	return payRate * hoursWorked;
}

double calculateDeductions(double grossIncome) {
	double totalDeductionAmount = EI + CPP;
	return grossIncome * totalDeductionAmount;
}