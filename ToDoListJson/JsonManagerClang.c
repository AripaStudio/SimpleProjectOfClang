//
// Created by VENUS on 7/6/2025.
//

#include "JsonManagerClang.h"

#include <ctype.h>
#include <stdio.h>

#include "Cjson/cJSON.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int Get_NewID(cJSON* root) {
    if (root == NULL) {
        return 0;
    }
    return cJSON_GetArraySize(root) + 1;
}



bool add_task_to_todolist(cJSON* root, const char* title, const char* description, const char* due_date, const char* status) {
    if (!root || !title || !description || !due_date || !status) {
        return false;
    }

    cJSON* tasks_array = cJSON_GetObjectItem(root, "tasks");
    if (!tasks_array) {
        tasks_array = cJSON_CreateArray();
        if (!tasks_array) {
            return false;
        }
        cJSON_AddItemToObject(root, "tasks", tasks_array);
    }
    int new_ID = Get_NewID(tasks_array);

    if (!cJSON_IsArray(tasks_array)) {
        return false;
    }

    cJSON* new_task = cJSON_CreateObject();
    if (!new_task) {
        return false;
    }

    cJSON_AddNumberToObject(new_task, "id", new_ID);
    cJSON_AddStringToObject(new_task, "title", title);
    cJSON_AddStringToObject(new_task, "description", description);
    cJSON_AddStringToObject(new_task, "due_date", due_date);
    cJSON_AddStringToObject(new_task, "status", status);

    cJSON_AddItemToArray(tasks_array, new_task);

    return true;
}

bool delete_item_from_json(cJSON* root , int id_to_delete) {
    if (!root) {
        return false;
    }

    cJSON* tasks_array = cJSON_GetObjectItem(root, "tasks");
    if (!tasks_array || !cJSON_IsArray(tasks_array)) {
        return false;
    }

    int array_size = cJSON_GetArraySize(tasks_array);
    for (int i = 0; i < array_size; i++) {
        cJSON* task_item = cJSON_GetArrayItem(tasks_array, i);
        if (task_item && cJSON_IsObject(task_item)) {
            cJSON* id_json = cJSON_GetObjectItem(task_item, "id");
            if (id_json && cJSON_IsNumber(id_json)) {
                int current_id = id_json->valueint;
                if (current_id == id_to_delete) {
                    cJSON_DeleteItemFromArray(tasks_array, i);
                    return true;
                }
            }
        }
    }
    return false;
}

cJSON* search_item_in_json(cJSON* root , int id_to_find) {
    if (!root) {
        return NULL;
    }

    cJSON* task_array = cJSON_GetObjectItem(root, "tasks");
    if (!task_array || !cJSON_IsArray(task_array)) {
        return NULL;
    }

    int array_size = cJSON_GetArraySize(task_array);
    for (int i = 0; i < array_size; i++) {
        cJSON* task_item = cJSON_GetArrayItem(task_array, i);
        if (task_item && cJSON_IsObject(task_item)) {
            cJSON* id_json = cJSON_GetObjectItem(task_item, "id");
            if (id_json && cJSON_IsNumber(id_json)) {
                int current_id = id_json->valueint;
                if (current_id == id_to_find) {
                    return task_item;
                }
            }
        }
    }
}

void show_json_content(cJSON* root) {
    if (!root) {
        printf("JSON is empty or invalid. \n ");
        return;
    }

    char* json_string = cJSON_Print(root);
    if (json_string) {
        printf("%s\n", json_string);
        free(json_string);
    }


}
bool save_json_to_file(cJSON* root , const char* filename) {
    if (!root || !filename) {
        return false;
    }
    char *json_string = cJSON_Print(root);
    if (!json_string) {
        return false;
    }

    FILE* fp = fopen(filename , "wb");
    if (!fp) {
        free(json_string);
        return false;
    }

    fprintf(fp, "%s\n", json_string);
    fclose(fp);
    free(json_string);
    return true;
}


bool MainMenu(const char* filename , cJSON* root) {
    printf("welcome to Todolist");
    printf("\n");
    Show_Help();
    char input[50];
    char inputIndexBuffer[10];

    while (true) {
        printf("you can type : ");
        if (fgets(input , sizeof(input) , stdin) != NULL) {
            input[strcspn(input, "\n")] = 0;
            string_to_lower(input);

            if (strcmp(input, "help") == 0) {
                Show_Help();
            }else if (strcmp(input, "exit") == 0) {
                return false;
            }else if (strcmp(input , "add") == 0) {
                char title[100];
                char description[200];
                char due_date[100];
                char status[100];
                if (fgets(title , sizeof(title) , stdin) != NULL) {
                    title[strcspn(title, "\n")] = 0;
                    if (fgets(description , sizeof(description) , stdin) != NULL) {
                        description[strcspn(description, "\n")] = 0;
                        if (fgets(due_date , sizeof(due_date) , stdin) != NULL) {
                            due_date[strcspn(due_date, "\n")] = 0;
                            if (fgets(status , sizeof(status) , stdin) != NULL) {
                                status[strcspn(status, "\n")] = 0;
                                add_task_to_todolist(root , title , description , due_date, status);
                            }
                        }
                    }
                }
            }else if (strcmp(input, "remove") == 0) {
                int id ;
            }else if (strcmp(input, "showall") == 0) {

            }else if (strcmp(input, "save") == 0) {

            }
        }
    }
}


void Show_Help() {
    printf("-----Commands-----\n");
    printf("For Add Data : add\n");
    printf("For Remove Data : remove\n");
    printf("ShowAllData : showall\n");
    printf("search a data : search\n");
    printf("\n");
    printf("save data : save\n");
    printf("\n");
    printf("for show This : help\n");
    printf("for Exit : exit\n");
    printf("-----Commands-----\n");
}


void string_to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}


