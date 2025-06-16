cmake_minimum_required(VERSION 3.31)
project(NumberGuessingGame C)

set(CMAKE_C_STANDARD 17)

add_executable(NumberGuessingGame main.c
        NumberGuessing.c
        NumberGuessing.h
        CL_Manager.c)
