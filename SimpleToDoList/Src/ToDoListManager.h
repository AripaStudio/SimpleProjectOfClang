#ifndef TODOLISTMANAGER_H
#define TODOLISTMANAGER_H

#include <stdbool.h>
#include <stddef.h>
#define STARTING_SIZE 4

typedef struct ToDoListStruct {
    char name[50];
    char title[100];
    char description[256];
    char dueDate[20];
    bool isCompleted;
} ToDoListStruct;

typedef struct ToDoListManager {
    ToDoListStruct *tasks;
    int count;
    int capacity;
} ToDoListManager;

ToDoListManager* CreateList();
void destroyTodoListManager(ToDoListManager *manager);
bool ensureCapacity(ToDoListManager *manager);

bool AddTask(ToDoListManager *manager, char name[50], char title[100], char description[256], char dueDate[20], bool isCompleted);
bool Main_menuManager(ToDoListManager *manager); // Changed to take ToDoListManager*
int convert_string_to_int(const char *str, int *result);

void string_to_lower(char *str);

ToDoListStruct* getTask(ToDoListManager *manager, int index);

void Show_Help();

bool addTask_inputList(ToDoListManager *manager, ToDoListStruct newTask);

bool removeTask(ToDoListManager *manager, int index);

void ShowData(ToDoListManager *manager);

bool EditTask(ToDoListManager *manager, int index, ToDoListStruct updatedTask); // Added manager and updatedTask params
bool SearchAndShow(char *inputBuffer, size_t bufferSize, ToDoListManager *manager); // Adjusted params
ToDoListStruct* SerachAndReturn(int taskIndex, ToDoListManager *manager);

#endif //TODOLISTMANAGER_H
