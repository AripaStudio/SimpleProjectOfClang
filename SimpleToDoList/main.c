#include <stdio.h>
#include  "Src/ToDoListManager.h"
#include <stdbool.h>

int main(void) {

    ToDoListManager *manager = CreateList();
    if (manager == NULL) {
        perror("Error in CreateList()\n");
        return -1;
    }


    while (true) {
        bool check = Main_menuManager(manager); // Corrected parameter
        if (check == false) {
            break;
        }
    }

    destroyTodoListManager(manager);
    return 0;
}
