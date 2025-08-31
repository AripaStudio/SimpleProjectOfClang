#include <stdbool.h>
#include <stdio.h>
#include  <string.h>
#include <ctype.h>
#include <stdlib.h>

int is_number(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

int WhileReturn(char Amalgar) {
    int SaveReturns[20];
    int Charkhe = 0;
    while (true) {
        char inputUser[20];
        printf("Please Enter your Number : ");
        printf("for Exit You Can type (exit)");
        if (fgets(inputUser, 20, stdin) == 0) {
            inputUser[strcspn(inputUser, "\n")] = 0;
            if (strcspn(inputUser , "exit") == 0) {
                size_t size = strlen(inputUser);
                switch (Amalgar) {
                    case '+':
                        Charkhe = 0;
                        for (int i = 0; i < size; ++i) {
                            Charkhe += inputUser[i];
                        }
                        break;
                    case '-':
                        if (Charkhe == 0 && Charkhe < Charkhe) {
                            if (Charkhe == 0 && Charkhe < Charkhe) {
                                Charkhe = SaveReturns[0];
                                for (int i = 1; i < Charkhe; ++i) {
                                    if (SaveReturns[i] > Charkhe) {
                                        printf("Error\n");
                                        break;
                                    }
                                    Charkhe -= SaveReturns[i];
                                }
                            }
                        }
                        break;
                    case '*':
                        Charkhe = 1;
                        for (int i = 0; i < size; ++i) {
                            Charkhe *= inputUser[i];
                        }
                        break;
                    case '/':
                        Charkhe = inputUser[0];
                        for (int i = 1; i < size; ++i) {
                            if (inputUser[i] == 0) {
                                printf(" \n Error");
                                break;
                            }
                            Charkhe /= inputUser[i];
                        }
                        break;
                    default:
                        printf("Qalat!\n");
                }


                return Charkhe;
            }
            if (is_number(inputUser)) {
                SaveReturns[Charkhe] = atoi(inputUser);
                Charkhe++;
            }
        }

    }
}


int MashinHesap(char Amalgar) {
    if (Amalgar == ' ' || Amalgar == '\n' || Amalgar == '\r' || Amalgar == '\t') {
        return 0;
    }
    WhileReturn(Amalgar);

}

int main(void){
    char op;
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &op);
    getchar();
    int finalResult = MashinHesap(op);
    printf("Final Result: %d\n", finalResult);
    return 0;
}