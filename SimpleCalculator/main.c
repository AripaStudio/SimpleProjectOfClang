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

    printf("Welcome to Simple C Calculator!\n");



    Help();
    while (true)
    {
        int num1, num2;
        int choice;



        printf("Enter Choice  1,2,3,4 or for help 5 for exit : 6");
        scanf("%d", &choice);


        while (getchar() != '\n');


        switch (choice) {
            case 5: {
                printf("--- Displaying menu again ---\n");
                continue;
            }
            case 6 : {
                printf("Exiting Calculator. Goodbye!\n");
                exit(0);
            }
            default:
                break;


        }

        if (choice >= 1 && choice <= 4) {
            printf("Enter first number: ");
            scanf("%d", &num1);
            while (getchar() != '\n');

            printf("Enter second number: ");
            scanf("%d", &num2);
            while (getchar() != '\n');
        } else {
            printf("Invalid choice! Please enter a number between 1 and 6.\n");
            printf("\n");
            continue;
        }


        switch (choice) {
            case 1:
                printf("Result: %d + %d = %d\n", num1, num2, add(num1, num2));
                break;
            case 2:
                printf("Result: %d - %d = %d\n", num1, num2, subtract(num1, num2));
                break;
            case 3:
                printf("Result: %d * %d = %d\n", num1, num2, multiply(num1, num2));
                break;
            case 4: {
                double div_result = divide(num1, num2);
                if (num2 == 0) {
                    printf("Error: Division by zero!\n");
                } else {
                    printf("Result: %d / %d = %.2f\n", num1, num2, div_result);
                }
                break;
            }
        }
        printf("\n");


    }
    return 0;
}


