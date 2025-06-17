cmake_minimum_required(VERSION 3.31)
project(SimpleToDoList C)

set(CMAKE_C_STANDARD 17)

add_executable(SimpleToDoList main.c
        Src/ToDoListManager.c
        Src/ToDoListManager.h)
