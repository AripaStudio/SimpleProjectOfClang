//
// Created by VENUS on 6/16/2025.
//
#include <stdbool.h>

#ifndef NUMBERGUESSING_H
#define NUMBERGUESSING_H

enum StatusEnum {
    playerCount = 0,
    win = 1,
    lose = 2,
    none = 3
};


int get_random_number(int MaxNumber);
void EditDataPlayer(enum StatusEnum status);
void Help_menu();
bool MainGame();
void ShowInfo();

void string_to_lower(char *str);

extern int gamesPlayedCount;
extern int playerLossesCount;
extern int playerWinsCount;


#endif //NUMBERGUESSING_H
