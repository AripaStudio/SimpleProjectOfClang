//
// Created by VENUS on 6/16/2025.
//
#include "NumberGuessing.h"
#include <ctype.h>

void string_to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]); // Cast to unsigned char is good practice
    }
}
