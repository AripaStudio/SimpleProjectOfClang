#include <stdio.h>
#include  "Src/ToDoListManager.h"

int main(void) {

     ToDoListManager *manager = CreateList();
     if (manager == NULL) {
       perror("Error in CreateList()\n");
         return -1;
     }

    while (true) {
        break;
    }


    destroyTodoListManager(manager);
}

