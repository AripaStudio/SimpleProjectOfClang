#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_number(const char *str) {
    if (str == 0 || *str == '\0') {
        return 0;
    }
    while (*str) {
        if (!isdigit(*str) && (*str != '-' || str != str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

int calculate(char op, const int numbers[], int count) {
    if (count == 0) {
        return 0;
    }

    int result = 0;
    switch (op) {
        case '+':
            result = 0;
            for (int i = 0; i < count; i++) {
                result += numbers[i];
            }
            break;
        case '-':
            result = numbers[0];
            for (int i = 1; i < count; i++) {
                result -= numbers[i];
            }
            break;
        case '*':
            result = 1;
            for (int i = 0; i < count; i++) {
                result *= numbers[i];
            }
            break;
        case '/':
            result = numbers[0];
            for (int i = 1; i < count; i++) {
                if (numbers[i] == 0) {
                    printf("Error: Division by zero\n");
                    return 0;
                }
                result /= numbers[i];
            }
            break;
        default:
            printf("Error: Invalid operator\n");
            return 0;
    }
    return result;
}

int process_input(char op) {
    int numbers[20];
    int count = 0;
    char buffer[20];
    printf("Please enter numbers (type 'exit' to calculate and quit):\n");
    while (true) {
        printf("> ");
        if (fgets(buffer, sizeof(buffer), stdin) == 0) {
            continue;
        }

        buffer[strcspn(buffer, "\n")] = 0;

        if (strcmp(buffer, "exit") == 0) {
            return calculate(op, numbers, count);
        }

        if (is_number(buffer)) {
            if (count < 20) {
                numbers[count] = atoi(buffer);
                count++;
            } else {
                printf("Error: Max number limit reached.\n");
            }
        } else {
            printf("Invalid input. Please enter a number.\n");
        }
    }
}

int main(void) {
    char op;
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &op);
    getchar();

    int final_result = process_input(op);
    printf("Final Result: %d\n", final_result);

    return 0;
}