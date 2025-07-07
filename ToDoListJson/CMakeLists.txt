cmake_minimum_required(VERSION 3.31)
project(ToDoListJson C)

set(CMAKE_C_STANDARD 17)

add_executable(ToDoListJson main.c
        JsonManager/JsonManagerClang.c
        JsonManager/JsonManagerClang.h
        Cjson/cJSON.c)
