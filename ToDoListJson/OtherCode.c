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
    //2,147,483,647 int.MAX
    if (len > 11) {
        return false;
    }


    long long result = 0;
    bool found_digit = false;
    bool is_negative = false;

    int start_index = 0;
    if (input[0] == '-') {
        is_negative = true;
        start_index = 1;
    }else if (input[0] == '+') {
        start_index = 1;
    }

    if (len == start_index) {
        return false;
    }

    for (int i = start_index; i < len; i++) {
        char c = input[i];

        if (c < '0' || c > '9') {
            return false;
        }

        int digit = c - '0';

        if (!is_negative) {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return false;
            }
        } else {
            if (result > (long)INT_MAX / 10 ||
                (result == (long)INT_MAX / 10 && digit > 8)) {
                return false;
                }
        }

        result = result * 10 + digit;
        found_digit = true;
    }
    if (!found_digit) {
        return false;
    }

    if (is_negative) {
        if (result > (long)INT_MAX + 1) {
            return false;
        }
        *output = (int)-result;
    } else {
        if (result > INT_MAX) {
            return false;
        }
        *output = (int)result;
    }

    return true;
}
