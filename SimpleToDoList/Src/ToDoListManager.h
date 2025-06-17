//
// Created by VENUS on 6/17/2025.
//

#ifndef TODOLISTMANAGER_H
#define TODOLISTMANAGER_H

#include <stdbool.h>
#define STARTING_SIZE 4

typedef struct ToDoListStruct {
    char name[50];
    char title[100];
    char description[256];
    char dueDate[20];
    bool isCompleted;
}ToDoListStruct;

typedef struct ToDoListManager {
    ToDoListStruct *tasks;
    int count;
    int capacity;
} ToDoListManager;


ToDoListManager* CreateList();
void destroyTodoListManager(ToDoListManager *manager);
static bool ensureCapacity(ToDoListManager *manager);


bool AddTask(ToDoListManager *manager , char name[50],char title[100],char description[256],char dueDate[20],bool isCompleted);

void string_to_lower(char *str);

ToDoListStruct* getTask(ToDoListManager *manager , int index);

void Show_Help();

bool addTask_inputList(ToDoListManager *manager, ToDoListStruct newTask);

bool removeTask(ToDoListManager *manager, int index);

void ShowData(ToDoListManager *manager);

bool Main_menuManager();











#endif //TODOLISTMANAGER_H
