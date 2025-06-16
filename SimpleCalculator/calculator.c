//
// Created by VENUS on 6/16/2025.
//

#include "calculator.h"


int add(int a , int b) {
    return a + b;
}

int subtract(int a , int b) {
    return a - b;
}

int multiply(int a , int b) {
    return a * b;
}

double divide(int a , int b) {
    if (a == 0) {
        return 0.0;
    }
    return (double)a / b;
}