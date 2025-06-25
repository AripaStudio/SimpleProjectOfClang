//
// Created by AripaStudio on 6/17/2025.
//

#include "ToDoListManager.h"

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

void Show_Help() {
    printf("-----Commands-----\n");
    printf("For Add Data : add\n");
    printf("For Remove Data : remove\n");
    printf("ShowAllData : showall\n");
    printf("search a data : search\n");
    printf("For Edit a Table : edit\n");
    printf("for show This : help\n");
    printf("for Exit : exit\n");
    printf("-----Commands-----\n");
}

bool addTask_inputList(ToDoListManager *manager, ToDoListStruct newTask){
    if (manager == NULL) {
        fprintf(stderr , "Error : List is Empty\n");
        return false;
    }
    if (!ensureCapacity(manager)) {
        return false;
    }

    strcpy(manager->tasks[manager->count].name, newTask.name);
    strcpy(manager->tasks[manager->count].title, newTask.title);
    strcpy(manager->tasks[manager->count].description, newTask.description);
    strcpy(manager->tasks[manager->count].dueDate, newTask.dueDate);
    manager->tasks[manager->count].isCompleted = newTask.isCompleted;

    manager->count++;
    return true;
}

ToDoListStruct* getTask(ToDoListManager *manager , int index) {
    if (manager == NULL || index < 0 || index >= manager->count) {
        fprintf(stderr, "Error : Invalid Index\n");
        return NULL;
    }
    return &(manager->tasks[index]);
}

bool removeTask(ToDoListManager *manager, int index) {
    if (manager == NULL || index < 0 || index >= manager->count) {
        fprintf(stderr, "Error : Invalid Index\n");
        return false;
    }
    printf("Removing Data, Title: %s and Index: %d\n", manager->tasks[index].title, index);

    for (int i = index; i < manager->count - 1; i++) {
        manager->tasks[i] = manager->tasks[i + 1];
    }
    manager->count--;
    printf("Complete remove Data.\n");
    return true;
}

void ShowData(ToDoListManager *manager) {
    if (manager == NULL || manager->count == 0) {
        fprintf(stderr, "Error : List is Empty\n");
        return;
    }
    for (int i = 0; i < manager->count; i++) {
        ToDoListStruct *task = getTask(manager , i);
        if (task != NULL) {
            printf("Task %d\n" , i + 1);
            printf("  Name: %s\n", task->name);
            printf("  Title: %s\n" , task->title);
            printf("  Description: %s\n" , task->description);
            printf("  DueDate: %s\n" , task->dueDate);
            printf("  IsCompleted: %s\n" , task->isCompleted ? "Yes" : "No");
            printf("--------------------\n");
        }
    }
}

bool EditTask(ToDoListManager *manager, int index, ToDoListStruct updatedTask) {
    if (manager == NULL || index < 0 || index >= manager->count) {
        fprintf(stderr, "Error: Invalid index for edit.\n");
        return false;
    }

    strcpy(manager->tasks[index].name, updatedTask.name);
    strcpy(manager->tasks[index].title, updatedTask.title);
    strcpy(manager->tasks[index].description, updatedTask.description);
    strcpy(manager->tasks[index].dueDate, updatedTask.dueDate);
    manager->tasks[index].isCompleted = updatedTask.isCompleted;

    printf("Task at index %d updated successfully.\n", index);
    return true;
}

bool AddTask(ToDoListManager *manager , char name[50],char title[100],char description[256],char dueDate[20],bool isCompleted) {
    if (manager == NULL) {
        printf("Error: ToDoListManager is NULL.\n");
        return false;
    }

    ToDoListStruct newTask;

    strcpy(newTask.name, name);
    strcpy(newTask.title, title);
    strcpy(newTask.description, description);
    strcpy(newTask.dueDate, dueDate);
    newTask.isCompleted = isCompleted;

    return addTask_inputList(manager, newTask);
}

void string_to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

bool SearchAndShow(char *inputBuffer, size_t bufferSize, ToDoListManager *manager) {
    if (fgets(inputBuffer, bufferSize, stdin) != NULL) {
        inputBuffer[strcspn(inputBuffer, "\n")] = 0;
        int taskIndex;
        int convertResult = convert_string_to_int(inputBuffer, &taskIndex);
        if (convertResult == 0) {
            ToDoListStruct* foundTask = getTask(manager, taskIndex);
            if (foundTask != NULL) {
                printf("Task Found: Name: %s, Title: %s, Due Date: %s\n",
                       foundTask->name, foundTask->title, foundTask->dueDate);
                return true;
            } else {
                printf("Task not found or invalid index.\n");
                return false;
            }
        } else {
            printf("Invalid input for index. Please enter a number.\n");
            return false;
        }
    }
    return false;
}

ToDoListStruct* SerachAndReturn(int taskIndex, ToDoListManager *manager) {
    return getTask(manager, taskIndex);
}

int convert_string_to_int(const char *str, int *result){
    long val;
    char *endptr;
    errno = 0;

    val = strtol(str, &endptr, 10);

    if (errno == ERANGE) {
        fprintf(stderr, "Error: Value '%s' out of long int range.\n", str);
        return -1;
    }
    if (endptr == str) {
        fprintf(stderr, "Error: No digits found in '%s'.\n", str);
        return -2;
    }
    while (isspace((unsigned char)*endptr)) {
        endptr++;
    }
    if (*endptr != '\0') {
        fprintf(stderr, "Error: Extra characters after number in '%s'. Remaining: '%s'\n", str, endptr);
        return -3;
    }
    if (val > INT_MAX || val < INT_MIN) {
        fprintf(stderr, "Error: Value '%s' out of int range.\n", str);
        return -4;
    }
    *result = (int)val;
    return 0;
}

bool Main_menuManager(ToDoListManager *manager) { // Corrected parameter type
    Show_Help();

    char input[50];
    char inputIndexBuffer[10];

    while (true) {
        printf("You Can Type : ");
        if (fgets(input, sizeof(input) , stdin) != NULL) {
            input[strcspn(input, "\n")] = 0;
            string_to_lower(input);

            if (strcmp(input , "add") == 0) {
                char name[50];
                char title[100];
                char description[256];
                char dueDate[20];
                char completedInput[10];
                bool isCompleted;

                printf("Enter name: ");
                if (fgets(name, sizeof(name), stdin) != NULL) {
                    name[strcspn(name, "\n")] = 0;
                } else {
                    fprintf(stderr, "Error reading name.\n");
                    continue;
                }

                printf("Enter title: ");
                if (fgets(title, sizeof(title), stdin) != NULL) {
                    title[strcspn(title, "\n")] = 0;
                } else {
                    fprintf(stderr, "Error reading title.\n");
                    continue;
                }

                printf("Enter description: ");
                if (fgets(description, sizeof(description), stdin) != NULL) {
                    description[strcspn(description, "\n")] = 0;
                } else {
                    fprintf(stderr, "Error reading description.\n");
                    continue;
                }

                printf("Enter due date (e.g.,YYYY-MM-DD): ");
                if (fgets(dueDate, sizeof(dueDate), stdin) != NULL) {
                    dueDate[strcspn(dueDate, "\n")] = 0;
                } else {
                    fprintf(stderr, "Error reading due date.\n");
                    continue;
                }

                printf("Is it completed? (yes/no): ");
                if (fgets(completedInput, sizeof(completedInput), stdin) != NULL) {
                    completedInput[strcspn(completedInput, "\n")] = 0;
                    string_to_lower(completedInput);
                    isCompleted = (strcmp(completedInput, "yes") == 0);
                } else {
                    fprintf(stderr, "Error reading completion status.\n");
                    continue;
                }

                if (AddTask(manager , name , title , description , dueDate , isCompleted)) {
                    printf("Task added successfully.\n");
                } else {
                    printf("Failed to add task.\n");
                }

            } else if (strcmp(input , "remove") == 0) {
                printf("Please Enter ID (Index) to remove (0-1-2-...): ");
                if (fgets(inputIndexBuffer , sizeof(inputIndexBuffer) , stdin) != NULL) {
                    inputIndexBuffer[strcspn(inputIndexBuffer, "\n")] = 0;
                    int indexToRemove;
                    if (convert_string_to_int(inputIndexBuffer, &indexToRemove) == 0) {
                        removeTask(manager, indexToRemove);
                    } else {
                        printf("Invalid index provided.\n");
                    }
                } else {
                    fprintf(stderr, "Error reading index for removal.\n");
                }
            } else if (strcmp(input , "edit") == 0) {
                printf("Please Enter ID (Index) for edit (0-1-2-...): ");
                if (fgets(inputIndexBuffer, sizeof(inputIndexBuffer) , stdin) != NULL) {
                    inputIndexBuffer[strcspn(inputIndexBuffer, "\n")] = 0;
                    int indexToEdit;
                    if (convert_string_to_int(inputIndexBuffer, &indexToEdit) == 0){
                        ToDoListStruct* taskToEdit = getTask(manager, indexToEdit);
                        if (taskToEdit != NULL) {
                            ToDoListStruct updatedTask;
                            char completedInput[10];

                            printf("Editing Task (Index %d, Title: %s)\n", indexToEdit, taskToEdit->title);
                            printf("Enter new name (leave blank to keep current: %s): ", taskToEdit->name);
                            if (fgets(updatedTask.name, sizeof(updatedTask.name), stdin) != NULL) {
                                updatedTask.name[strcspn(updatedTask.name, "\n")] = 0;
                                if (strlen(updatedTask.name) == 0) strcpy(updatedTask.name, taskToEdit->name);
                            } else { fprintf(stderr, "Error reading new name.\n"); continue; }

                            printf("Enter new title (leave blank to keep current: %s): ", taskToEdit->title);
                            if (fgets(updatedTask.title, sizeof(updatedTask.title), stdin) != NULL) {
                                updatedTask.title[strcspn(updatedTask.title, "\n")] = 0;
                                if (strlen(updatedTask.title) == 0) strcpy(updatedTask.title, taskToEdit->title);
                            } else { fprintf(stderr, "Error reading new title.\n"); continue; }

                            printf("Enter new description (leave blank to keep current: %s): ", taskToEdit->description);
                            if (fgets(updatedTask.description, sizeof(updatedTask.description), stdin) != NULL) {
                                updatedTask.description[strcspn(updatedTask.description, "\n")] = 0;
                                if (strlen(updatedTask.description) == 0) strcpy(updatedTask.description, taskToEdit->description);
                            } else { fprintf(stderr, "Error reading new description.\n"); continue; }

                            printf("Enter new due date (leave blank to keep current: %s): ", taskToEdit->dueDate);
                            if (fgets(updatedTask.dueDate, sizeof(updatedTask.dueDate), stdin) != NULL) {
                                updatedTask.dueDate[strcspn(updatedTask.dueDate, "\n")] = 0;
                                if (strlen(updatedTask.dueDate) == 0) strcpy(updatedTask.dueDate, taskToEdit->dueDate);
                            } else { fprintf(stderr, "Error reading new due date.\n"); continue; }

                            printf("Is it completed? (yes/no, current: %s): ", taskToEdit->isCompleted ? "yes" : "no");
                            if (fgets(completedInput, sizeof(completedInput), stdin) != NULL) {
                                completedInput[strcspn(completedInput, "\n")] = 0;
                                string_to_lower(completedInput);
                                updatedTask.isCompleted = (strcmp(completedInput, "yes") == 0);
                            } else { fprintf(stderr, "Error reading new completion status.\n"); continue; }

                            EditTask(manager, indexToEdit, updatedTask);
                        } else {
                            printf("Task not found for editing.\n");
                        }
                    } else {
                        printf("Invalid index provided for edit.\n");
                    }
                } else {
                    fprintf(stderr, "Error reading index for edit.\n");
                }
            } else if (strcmp(input , "showall") == 0) {
                ShowData(manager);
            } else if (strcmp(input , "search") == 0) {
                printf("Please Enter ID (Index) for search (0-1-2-...): ");
                SearchAndShow(inputIndexBuffer, sizeof(inputIndexBuffer), manager);
            } else if (strcmp(input , "help") == 0) {
                Show_Help();
            } else if (strcmp(input , "exit") == 0) {
                return false;
            } else {
                printf("Please Enter a Valid Command : help \n");
            }
        } else {
            fprintf(stderr, "Error reading command.\n");
            return false;
        }
    }
}




