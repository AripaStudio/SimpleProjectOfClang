#include <stdio.h>
#include "calculator.h"
#include <stdbool.h>
#include <stdlib.h>


void Help()
{
    printf("\nChoose an operation:\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Show Help Menu \n");
    printf("6. for Exit \n");
    printf("Enter your choice (1-6): ");
}

int main(void) {
    int choice;
    printf("Welcome to Simple C Calculator!\n");

    printf("Enter Choice  1,2,3,4 or for help 5 for exit : 6");
    scanf("%d", &choice);

    if (choice < 1 || choice > 6) {

    }

    Help();
    while (true)
    {
        int num1, num2;




        printf("Welcome to Simple C Calculator!\n");
        printf("Enter first number: ");
        scanf("%d", &num1); // Read first integer

        printf("Enter second number: ");
        scanf("%d", &num2); // Read second integer


        switch (choice) {
            case 1:
                printf("Result: %d + %d = %d\n", num1, num2, add(num1, num2));
                break;
            case 2:
                printf("Result: %d - %d = %d\n", num1, num2, sub(num1, num2));
                break;
            case 3:
                printf("Result: %d * %d = %d\n", num1, num2, mul(num1, num2));
                break;
            case 4: {
                double div_result = div(num1, num2);
                if (num2 == 0) {
                    printf("Error: Division by zero!\n");
                } else {
                    printf("Result: %d / %d = %.2f\n", num1, num2, div_result); // %.2f for 2 decimal places
                }
                break;
            }
            case 5:
                Help();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
        return 0;
    }
}


