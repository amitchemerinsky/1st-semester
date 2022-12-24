#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
// I use this warning because of the scanf function

/*******
Amit Chemerinsky
322211590
83120-02
Ex2
********/

int main()
{

	char firstname, lastname;
	int choice;
	// yes = A condition for the continuation of the main loop 
	int yes = 1;

	// Declaration of variables for case 1
	double a, b, c;
	double discriminant, root1, root2;
	double realPart, imagPart;

	// Declaration of variables for case 2 and 3
	int num1, num2, mn, upperBound;
	// check = A condition for the continuation the inner loop
	int check;
	int isMersenne;

	// Declaration of variables for case 4
	int s, i, j;
	int shapeChoose;

	// Declaring functions for case 4 - Explanation of each function below.
	void line1(int);
	void line2(int);
	void line3(int);
	void line4(int);
	void line5(int);

	printf("Hello,\nWhat is the first letter of your first name?\n");
	scanf(" %c", &firstname);
	printf("What is the first letter of your last name?\n");
	scanf(" %c", &lastname);

	// Check if the first character of the firstname variable is a lowercase letter
	if (firstname >= 'a' && firstname <= 'z')
	{
		// If it is, convert it to uppercase using the toupper function
		firstname = ("%c", toupper(firstname));
	}
	if (lastname >= 'a' && lastname <= 'z')
	{
		lastname = ("%c", toupper(lastname));
	}
	printf("Hello %c. %c, welcome to our menu!\n", firstname, lastname);

	// I use yes instead of boolian - to check weather to run the loop again
	while (yes)
	{
		printf("Choose 1 for equations, 2 for Fizz Buzz, 3 for Mersenne numbers, 4 for shapes and -1 for exit\n");
		scanf(" %d", &choice);
		switch (choice)
		{

		case 1:

			printf("Welcome to quadratic equation!\nEnter coefficients a, b and c: \n");
			scanf(" %lf%lf%lf", &a, &b, &c);

			printf("The quadratic equation is\n");
			// check all the combiation of 0 and 1
			if (a == 0 && b != 0 && c != 0) {
				printf("%.2lfX + %.2lf = 0\n", b, c);
			}
			else if (a == 1 && b == 0 && c != 0 && c != 1) {
				printf("X^2 + %.2lf = 0\n", c);
			}
			else if (a == 1 && b != 0 && b != 1 && c == 0) {
				printf("X^2 + %.2lfX = 0\n", b);
			}
			else if (b == 0 && a != 0 && c != 0) {
				printf("%.2lfX^2 + %.2lf = 0\n", a, c);
			}
			else if (a == 1 && b == 0 && c == 0) {
				printf("X^2 = 0\n");
			}
			else if (c == 0 && a != 0 && b != 0) {
				printf("%.2lfX^2 + %.2lfX = 0\n", a, b);
			}
			else if (a == 0 && b == 0 && c != 0) {
				printf("%.2lf = 0\n", c);
			}
			else if (b == 0 && c == 0 && a != 0) {
				printf("%.2lfX^2 = 0\n", a);
			}
			else if (a == 0 && c == 0 && b != 0) {
				printf("%.2lfX = 0\n", b);
			}
			else if (a == 0 && b == 0 && c == 0) {
				printf("");
			}
			else if (a == 1 && b == 1 && c == 1) {
				printf("X^2 + X + 1.00 = 0\n");
			}
			else if (a == 1 && b == 1 && c != 1) {
				printf("X^2 + X + %.2lf = 0\n", c);
			}
			else if (a == 1 && b != 1 && c == 1) {
				printf("X^2 + %.2lfX + 1.00 = 0\n", b);
			}
			else if (a != 1 && b == 1 && c == 1) {
				printf("%.2lfX^2 + X + 1.00 = 0\n", a);
			}
			else if (a == 1 && b != 1 && c != 1) {
				printf("X^2 + %.2lfX + %.2lf = 0\n", b, c);
			}
			else if (b == 1 && a != 1 && c != 1) {
				printf("%.2lfX^2 + X + %.2lf = 0\n", a, c);
			}
			else if (c == 1 && a != 1 && b != 1) {
				printf("%.2lfX^2 + %.2lfX + 1 = 0\n", a, b);
			}
			else if (a == 0 && b == 0 && c == 1) {
				printf("1 = 0\n");
			}
			else if (a == 0 && b == 1 && c == 0) {
				printf("X = 0\n");
			}
			else if (a == 1 && b == 0 && c == 0) {
				printf("X^2 = 0\n");
			}
			else if (a == 1 && b == 1 && c == 0) {
				printf("X^2 + X = 0\n");
			}
			else if (a == 1 && b == 0 && c == 1) {
				printf("X^2 + 1 = 0\n");
			}
			else if (a == 0 && b == 1 && c == 1) {
				printf("X + 1 = 0\n");
			}
			else if (a != 1 && b != 1 && c != 1) {
				printf("%.2lfX^2 + %.2lfX + %.2lf = 0\n", a, b, c);
			}
			else if (a != 0 && b != 0 && c != 0)
				printf("%.2lfX^2 + %.2lfX + %.2lf = 0\n", a, b, c);
			else if (a != 0 && b != 0 && c == 0) {
				printf("%.2lfX^2 + %.2lfX = 0\n", a, b);
			}

			discriminant = (b * b) - (4 * a * c);

			if (a == 0 && b == 0 && c != 0) {
				// No solution if a, b, and c are all 0
				printf("No solution!\n");

			}

			else if (a == 0 && b == 0 && c == 0) {
				// All real numbers are solutions if a, b, and c are all 0
				printf("0=0\n");
			}

			else if (a == 0 && b != 0)
			{
				printf("root = %.2lf\n", -c / b);
			}

			// condition for real and different roots
			else if (discriminant > 0)
			{
				root1 = (-b + sqrt(discriminant)) / (2 * a);
				root2 = (-b - sqrt(discriminant)) / (2 * a);

				if (root1 > root2)
				{
					printf("root1 = %.2lf and root2 = %.2lf\n", root2, root1);
				}


				if (root1 < root2)
				{
					printf("root1 = %.2lf and root2 = %.2lf\n", root1, root2);
				}

			}
			// condition for real and equal roots
			else if (discriminant == 0)
			{
				root1 = root2 = -1 * b / (2 * a);
				// check if root1 is equal to -0.00
				if (root1 == -0.00)
				{
					printf("root1 = root2 = 0.00\n");
				}
				else
				{
					printf("root1 = root2 = %.2lf\n", root1);
				}
			}
			// if roots are not real
			else if (discriminant < 0)
			{
				realPart = -b / (2 * a);
				// Calculate the imaginary part of the roots
				imagPart = sqrt(-discriminant) / (2 * a);

				// Check if the real part is 0
				if (realPart == 0)
				{
					// Print roots with only imaginary parts
					printf("root1 = -%.2lfi and root2 = +%.2lfi\n", imagPart, imagPart);
				}
				else if (imagPart == 0)
				{
					// Print roots with only real parts
					printf("root1 = %.2lf and root2 = %.2lf\n", realPart, realPart);
				}
				else
					// Print roots with both real and imaginary parts
					printf("root1 = %.2lf-%.2lfi and root2 = %.2f+%.2fi\n", realPart, imagPart, realPart, imagPart);
			}


			break;



		case 2:

			printf("Welcome to Fizz Buzz!\n");
			printf("Enter 2 numbers between 2-9 (single digit each): \n");

			do
			{
				scanf(" %d", &num1);
				scanf(" %d", &num2);

				// Check that num1 and num2 are between 2 and 9, and are not equal
				if (num1 >= 2 && num1 <= 9 && num2 >= 2 && num2 <= 9 && num1 != num2)
				{

					// If num1 is greater than num2, swap them
					if (num1 > num2)
					{
						int temp = num1;
						num1 = num2;
						num2 = temp;
					}
					check = 1;
					//Set check to 1 to exit the loop
				}
				else
				{
					// Set check to 0 to stay in the loop
					check = 0;
				}
			} while (!check);
			check = 1;
			do
			{
				printf("Enter a two-digit number: \n");
				scanf(" %d", &upperBound);
				// Check that l is a two-digit number
				if (upperBound < 10 || upperBound > 99)
				{
					check = 0;
				}
				else
				{
					check = 1;
				}
			} while (!check);

			// Iterate from 1 to l
			for (i = 1; i <= upperBound; i++)
			{
				// Check for FizzBuzz, Fizz, Buzz, or just the number
				if (i % num1 == 0 && i % 10 == num2)
				{
					// Print "FizzBuzz" if i is divisible by num1 and the last digit of i is num2
					printf("FizzBuzz \n");
				}
				else if (i % num1 == 0)
				{
					// Print "Fizz" if i is divisible by num1
					printf("Fizz \n");
				}
				else if (i % 10 == num2)
				{
					// Print "Buzz" if the last digit of i is num2
					printf("Buzz \n");
				}
				else
				{
					printf("%d \n", i);
				}
			}


			break;

			// This block of code is executed when the value of the "choice" variable is 3
		case 3:
			// Set the check flag to 1
			check = 1;
			printf("Welcome to Mersenne numbers!\n");
			printf("Enter 2 positive numbers smaller than 1000: \n");
			// Start a do-while loop
			do
			{
				scanf(" %d", &num1);
				scanf(" %d", &num2);

				if (num1 == num2)
				{
					// Set the isMersenne flag to 0
					isMersenne = 0;
					int p = 0;
					int n1 = num1 + 1;
					// Start an infinite loop
					for (i = 0;; i++)
					{
						p = (int)pow(2, i);
						if (p > n1)
						{
							break;
						}
						// If p is equal to n1, set the isMersenne flag to 1
						else if (p == n1)
						{

							isMersenne = 1;
						}
					}
					if (isMersenne)
					{
						printf("%d", num1);
					}
					else {
						printf("None\n");
					}
				}
				// Check if both num1 and num2 are within the range of 1 to 999
				if (num1 >= 1 && num1 < 1000 && num2 >= 1 && num2 < 1000)
				{
					check = 1;
					// If num1 is greater than num2, swap the values of num1 and num2
					if (num1 > num2)
					{
						int temp = num1;
						num1 = num2;
						num2 = temp;
					}
				}
				else
				{
					check = 0;
				}


			} while (!check);

			for (i = 1; i > 0; i++)
			{
				mn = pow(2, i) - 1;
				if (mn > num2)
				{
					break;

				}
				if (mn >= num1)
				{
					printf("%d\n", mn);
				}

			}

			break;


		case 4:
			check = 1;

			printf("Welcome to Shapes!\n");
			printf("What shape do you want to pick ?1 for square, 2 for triangle, 3 for star\n");
			scanf(" %d", &shapeChoose);

			switch (shapeChoose)
			{

			case 1:
				// shape of square
				printf("Enter size (10-20): \n");
				do {
					scanf(" %d", &s);
					if (s >= 10 && s <= 20)
					{
						check = 1;

					}
					else
					{
						check = 0;
					}

				} while (!check);

				/* Row iterator for loop */
				for (i = 0; i < s; i++)
				{
					/* Column iterator for loop */
					for (j = 0; j < s; j++)
					{
						/* Check if currely position is a boundary position */
						if (i == 0 || i == s - 1 || j == 0 || j == s - 1)
							printf("O");
						else
							printf("-");
					}
					printf("\n");
				}

				break;

			case 2:
				// shape of triangle
				printf("Enter size (10-20): \n");
				do {
					scanf(" %d", &s);
					if (s >= 10 && s <= 20)
					{
						check = 1;

					}
					else
					{
						check = 0;
					}

				} while (!check);

				for (i = 1; i <= 2 * s + 1; i++)
				{
					for (j = 1; j <= i; j++)
					{
						if (j == 1 || i == j || i == 2 * s + 1)
						{
							printf("O");
						}
						else
							printf("-");
					}
					printf("\n");
				}

				break;



			case 3:
				// shape of star
				printf("Enter size (10-20): \n");
				do {
					scanf(" %d", &s);
					if (s >= 10 && s <= 20)
					{
						check = 1;

					}
					else
					{
						check = 0;
					}

				} while (!check);

				/*
				Function name: line1 ;
				Input: int s - an integer representing the size of the pattern to be printed.
				Output: None (the function prints to the screen, but does not return a value).
				Function operation: The line1 function prints a single line of a pattern with a central
				"O" character, surrounded by hyphens. The size of the pattern is determined by the input s,
				which specifies the number of hyphens on either side of the central "O" character.
				The function uses two nested for loops to iterate through the characters in the
				pattern and print them to the screen.
				*/
				line1(s);
				/*
				Function name: line2
				Input: int s - an integer representing the size of the pattern to be printed
				Output: None (the function prints to the screen, but does not return a value)
				Function operation: The line2 function prints a single line of a pattern with "O"
				characters on either side of the center, surrounded by hyphens.
				The size of the pattern is determined by the input s, which specifies the number of
				hyphens on either side of the "O" characters.
				*/
				line2(s);
				/*
				Function name: line3
				Input: int s - an integer representing the size of the pattern to be printed
				Output: None
				The line3 function prints a single line of a pattern with "O" characters.
				The size of the pattern is determined by the input s, which specifies the number of "O"
				characters in the line.
				*/
				line3(s);
				/*
				Function name: line4
				Input: int s - an integer representing the size of the pattern to be printed
				Output: None
				The line4 function prints a single line of a pattern with "O" characters at the second
				and second-to-last positions, surrounded by hyphens. The size of the pattern is determined
				by the input s, which specifies the number of hyphens on either side of the "O" characters.
				*/
				line4(s);
				/*
				Function name: line5
				Input: int s - an integer representing the size of the pattern to be printed
				Output: None (the function prints to the screen, but does not return a value)
				Function operation: The line5 function prints a single line of a pattern with "O"
				characters at the third and third-to-last positions, surrounded by hyphens.
				The size of the pattern is determined by the input s, which specifies the number of
				hyphens on either side of the "O" characters.
				*/
				line5(s);
				line4(s);
				line3(s);
				line2(s);
				line1(s);

				break;

			}

			break;


		case -1:
			printf("Thank you, %c. %c, have a nice day!\n", firstname, lastname);
			exit(0);

		default:
			break;

		} // end of the switch-case
		


	}
	return 0;
}

int i, j, s;
void line1(int s) {
	for (i = 1; i < 2; i++) {
		for (j = 1; j <= 2 * s - 1; j++) {
			if (j == s) {
				printf("O");
			}
			else {
				printf("-");
			}
		}
		printf("\n");
	}
}
void line2(int s) {
	for (i = 2; i < 3; i++) {
		for (j = 1; j <= 2 * s - 1; j++) {
			if (j == s + 1 || j == s - 1) {
				printf("O");
			}
			else {
				printf("-");
			}
		}
		printf("\n");
	}
}
void line3(int s) {
	for (i = 3; i < 4; i++) {
		for (j = 1; j <= 2 * s - 1; j++) {
			printf("O");
		}
		printf("\n");
	}
}
void line4(int s) {
	for (i = 4; i < 5; i++) {
		for (j = 1; j <= 2 * s - 1; j++) {
			if (j == 2 * s - 2 || j == 2) {
				printf("O");
			}
			else {
				printf("-");
			}
		}
		printf("\n");
	}
}
void line5(int s) {
	for (i = 5; i < 6; i++) {
		for (j = 1; j <= 2 * s - 1; j++) {
			if (j == 2 * s - 3 || j == 3) {
				printf("O");
			}
			else {
				printf("-");
			}
		}
		printf("\n");
	}
}

