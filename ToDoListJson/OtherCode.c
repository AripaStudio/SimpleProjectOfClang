//
// Created by VENUS on 7/9/2025.
//

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include  "JsonManagerClang.h"


void string_to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

bool ConvertStringToIntAndCheck(char* input , int* output) {
    if (input == NULL) {
        return false;
    }

    int sizeInput = strlen(input);
    if (sizeInput == 0) {
        return false;
    }
    int LastLength = sizeInput - 1;
    bool checkForeach = false;
    for (int i = 0; i < sizeInput; i++) {
        char c = input[i];
        if (c >= '0' && c <= '9') {
            if (i < LastLength) {
                checkForeach = true;
            }
        }else {
            return false;
        }
    }
    if (checkForeach) {
        *output = atoi(input);
        return true;
    }
    return false;
}
