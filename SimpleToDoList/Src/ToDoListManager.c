//
// Created by VENUS on 6/17/2025.
//

#include "ToDoListManager.h"

#include <ctype.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
          fprintf(stderr , "Error : List is Empty ");
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
    printf("Complete Add Data");
    return true;
}

ToDoListStruct* getTask(ToDoListManager *manager , int index) {
    if (manager == NULL || index < 0 || index >= manager->count) {
        fprintf(stderr, "Error : Invalid Index ");
        return NULL;
    }
    return &(manager -> tasks[index]);
}

bool removeTask(ToDoListManager *manager, int index) {
    if (manager == NULL || index < 0 || index >= manager->count) {
        fprintf(stderr, "Error : Invalid Index ");
        return false;
    }
    printf("Remove Data , Titel :  %s and Index : %d " , manager->tasks[index].title , index);

    for (int i = index; i < manager->count - index; i++) {
        manager->tasks[i] = manager->tasks[i + 1];
    }
    manager->count--;
    printf("complete remove Data");
    return true;
}

void ShowData(ToDoListManager *manager) {
 if (manager == NULL || manager->count == 0) {
     fprintf(stderr, "Error : List is Empty ");
     return;
 }
    for (int i = 0; i < manager->count; i++) {
        ToDoListStruct *task = getTask(manager , i);
        if (task != NULL) {
            printf("Task %d \n" , i + 1);
            printf("Title : %s \n" , task->title);
            printf("Description : %s \n" , task->description);
            printf("DueDate : %s \n" , task->dueDate);
            printf("IsCompleted : %d\n" , task->isCompleted);
            printf("Complete Add Data");
        }
    }
}

bool EditTask() {
    //later
    return false;
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

int convert_string_to_int(const char *str, int *result) {
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

bool Main_menuManager(ToDoListStruct *manager) {
    Show_Help();

    char input[50];
    char inputIndex[9];

    while (true)
        {
        printf("You Can Type : ");
        if (fgets(input, sizeof(input) , stdin) != NULL)
            {
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
                }

                printf("Enter title: ");
                if (fgets(title, sizeof(title), stdin) != NULL) {
                    title[strcspn(title, "\n")] = 0;
                }

                printf("Enter description: ");
                if (fgets(description, sizeof(description), stdin) != NULL) {
                    description[strcspn(description, "\n")] = 0;
                }

                printf("Enter due date (e.g., YYYY-MM-DD): ");
                if (fgets(dueDate, sizeof(dueDate), stdin) != NULL) {
                    dueDate[strcspn(dueDate, "\n")] = 0;
                }

                printf("Is it completed? (yes/no): ");
                if (fgets(completedInput, sizeof(completedInput), stdin) != NULL) {
                    completedInput[strcspn(completedInput, "\n")] = 0;
                    string_to_lower(completedInput);

                    isCompleted = (strcmp(completedInput, "yes") == 0);
                }
                    printf("Task added .\n");
                    AddTask(manager , name , title , description , dueDate , isCompleted);

            }else if (input == "remove") {
                if (fgets(inputIndex , sizeof(input) , stdin) != NULL) {
                    inputIndex[strcspn(inputIndex, "\n")] = 0;
                    removeTask(manager, inputIndex);
                }
            }else if (strcmp(input , "edit") == 0) {
                printf("Later");
            }else if (strcmp(input , "showall") == 0) {
               ShowData(manager);
            }else if (strcmp(input , "search") == 0) {
                printf("Please Enter ID (Index) for search (0-1-2-3-...): ");

                if (fgets(inputIndex , sizeof(inputIndex) , stdin) != NULL)
                    {
                    inputIndex[strcspn(inputIndex, "\n")] = 0;
                    int taskIndex;
                    int Convert = convert_string_to_int(inputIndex, &taskIndex);
                    if (Convert == 0)
                    {
                        ToDoListStruct* foundTask = getTask(manager, taskIndex);
                        if (foundTask != NULL)
                        {
                            printf("Task Found: Name: %s, Title: %s, Due Date: %s\n",
                            foundTask->name, foundTask->title, foundTask->dueDate);
                        }else
                        {
                            printf("Task not found or invalid index.\n");
                        }
                    }else {
                        printf("Invalid input for index. Please enter a number.\n");
                    }

                }
            }else if (strcmp(input , "help") == 0) {
                Show_Help();
            }else if (strcmp(input , "exit") == 0)
            {
                return false;
            }else {
                printf("Please Enter a Valid Command : help \n");
            }
        }
    }
}



