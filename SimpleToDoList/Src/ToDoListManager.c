//
// Created by VENUS on 6/17/2025.
//

#include "ToDoListManager.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>


void Show_Help() {
    printf("-----Commands-----\n");
    printf("For Add Data : add");
    printf("For Remove Data : remove");
    printf("ShowAllData : showall");
    printf("search a data : search");
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


bool Main_menuManager() {
    return false;
}



