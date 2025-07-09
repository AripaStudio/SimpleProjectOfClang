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

bool ConvertStringToIntAndCheck(const char* input, int* output) {
    if (input == NULL || output == NULL) {
        return false;
    }
    int len = strlen(input);
    if (len == 0) {
        return false;
    }
    bool found_digit = false;

    for (int i = 0; i < len; i++) {
        char c = input[i];

        if (i == 0 && (c == '-' || c == '+')) {
            continue;
        }

        if (c < '0' || c > '9') {
            return false;
        }


        found_digit = true;
    }
    if (!found_digit) {
        return false;
    }
    *output = atoi(input);
    return true;
}
