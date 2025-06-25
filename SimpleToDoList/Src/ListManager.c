//
// Created by AripaStudio on 6/17/2025.
//

#include <stdio.h>
#include <stdlib.h>

#include "ToDoListManager.h"

ToDoListManager* CreateList() {
    ToDoListManager *manager = (ToDoListManager*)malloc(sizeof(ToDoListManager));
    if (manager == NULL) {
        perror("Memory allocation error for ToDoListManager");
        return NULL;
    }

    manager->tasks = (ToDoListStruct*)malloc(STARTING_SIZE * sizeof(ToDoListStruct));
    if (manager->tasks == NULL) {
        perror("Memory allocation error for tasks array");
        free(manager); // Free the manager itself if tasks allocation fails
        return NULL;
    }

    manager->count = 0;
    manager->capacity = STARTING_SIZE;
    return manager;
}

bool ensureCapacity(ToDoListManager *manager) {
    if (manager->count == manager->capacity) {
        int newCapacity = manager->capacity * 2;
        printf("New capacity = %d\n", newCapacity);
        ToDoListStruct *temp = (ToDoListStruct*)realloc(manager->tasks, newCapacity * sizeof(ToDoListStruct));
        if (temp == NULL) {
            perror("Memory allocation error: in ensureCapacity");
            return false;
        }
        manager->tasks = temp;
        manager->capacity = newCapacity;
        printf("New capacity = %d\n", manager->capacity);
    }
    return true;
}

void destroyTodoListManager(ToDoListManager *manager) {
    if (manager != NULL) {
        if (manager->tasks != NULL) {
            free(manager->tasks);
            manager->tasks = NULL;
        }
        free(manager);
        printf("ToDoListManager destroyed\n");
    }
}