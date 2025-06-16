#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <time.h>

#include "NumberGuessing.h"

int main(void) {
    srand(time(NULL));
    printf("Welcome to the Number Guessing Program\n");

    char inputUser[10];
    //exit
    //info
    //start

    Help_menu();
    while (true)
    {
        printf("\n Please enter (Start , Exit , Info )");
        if (fgets(inputUser, sizeof(inputUser), stdin) == NULL)
        {
            inputUser[strcspn(inputUser, "\n")] = '\0';

            if (strcmp(inputUser, "exit") == 0) {
                break;
            } else if (strcmp(inputUser, "info") == 0) {
                printf("Displaying game information.\n");
                ShowInfo();
            }else if (strcmp(inputUser, "start") == 0) {
                printf("Starting the game ...\n");
                MainGame();
            }else {
                printf("Wrong input.\n");
            }
        }else {
            printf("Error reading input.\n");
            printf("Please enter (Start , Exit , Info )");
        }

    }
    return 0;
}