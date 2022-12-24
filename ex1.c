#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*******
Amit Chemerinsky
322211590
83120-02
Ex1
********/
int main()
{
    int num1, num2;
    printf("\"%% %% hello \\/\\/orld %% %% \"%%c\"\n");

    printf("Enter 2 numbers \n");
    scanf("%d %d", &num1, &num2);
    printf("The sum of %d and %d is: %d\n", num1, num2, num1 + num2);
    printf("The sub of %d and %d is: %d\n", num1, num2, num1 - num2);
    printf("The mul of %d and %d is: %d\n", num1, num2, num1 * num2);
    printf("The div of %d and %d is: %d\n", num1, num2, num1 / num2);
    printf("The mod of %d and %d is: %d\n", num1, num2, num1 % num2);

    char letterA, letterB, letterC, letterD;
    printf("Enter four lowercase letters as password \n");
    scanf(" %c %c %c %c", &letterA, &letterB, &letterC, &letterD);
    printf("Your uppercase password is: %c%c%c%c\n", toupper(letterA), toupper(letterB), toupper(letterC), toupper(letterD));

    int binaryNum;
    int ones, tens, hundreds, thousands, result;
    printf("Enter a 4 digits binary number \n");
    scanf("%d", &binaryNum);
    // Converts binary number to decimal numbers
    thousands = binaryNum / 1000;
    hundreds = (binaryNum % 1000) / 100;
    tens = (binaryNum - (thousands * 1000 + hundreds * 100)) / 10;
    ones = (binaryNum - (thousands * 1000 + hundreds * 100)) % 10;
    result = ones + tens * 2 + hundreds * 2 * 2 + thousands * 2 * 2 * 2;
    printf("%d\n", result);

    int phoneNumber;
    printf("Enter phone number \n");
    scanf("%d", &phoneNumber);
    printf("Internal number: 0-%d\n", phoneNumber);
    printf("Universal number: +972-%d\n", phoneNumber);



        
    return 0;
}