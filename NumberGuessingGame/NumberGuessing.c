//
// Created by VENUS on 6/16/2025.
//

#include "NumberGuessing.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>



int get_random_number(int MaxNumber)
{
    if (MaxNumber <= 0)
    {
        return 0;
    }
    int output = (rand() % MaxNumber) + 1;
    return output;
}


int gamesPlayedCount = 0;
int playerLossesCount = 0;
int playerWinsCount = 0;

void EditDataPlayer(enum StatusEnum status)
{
    switch (status) {
        case playerCount:
            gamesPlayedCount++;
            break;
        case win:
            playerWinsCount++;
            break;

        case lose:
            playerLossesCount++;
            break;
        case none:
            break;
        default:
            printf("Error in Edit Data Player ");
            break;


    }
}

void Help_menu()
{
    printf("Welcome to this game! To play, simply enter a number between 1 and 100.\n");
    printf("If the number you entered is greater than the random number, you will be notified, and similarly for a smaller number.\n");
    printf("For Start Game : Start\n");
    printf("To exit the game: exit\n");
    printf("To see your game information: info\n");
}

void ShowInfo() {
    printf("Game Information:\n");
    printf("Player Count: %d\n", gamesPlayedCount);
    printf("Player Wins: %d\n", playerWinsCount);
    printf("Player Losses: %d\n", playerLossesCount);
    printf("Thank you for playing\n");
}


bool MainGame()
{
    EditDataPlayer(0);
    Help_menu();
    int Guess = get_random_number(100);
    int UserGuess ;
    int numerGuess = 5;
        while (numerGuess > 0)
        {
        printf("Please Enter a Number : \n");
        scanf("%d", &UserGuess);
        while (getchar() != '\n');

        if (UserGuess == Guess) {
            printf("Congratulations! You won!\n");
            EditDataPlayer(1);
            return true;
        }else if (UserGuess > Guess)
        {
            printf("Your guess is too high.\n");
            numerGuess--;
        }else {
            printf("Your guess is too low.\n");
            numerGuess--;
        }
    }
    if (numerGuess == 0) {
        EditDataPlayer(2);
        printf("You Lose\n");
        printf("answer : %d" , Guess);
        return false;
    }
    return false;

}
