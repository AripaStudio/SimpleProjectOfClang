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

bool add_item_to_json(cJSON* root , const char* key , const char* value) {
    if (!root || !key || !value) {
        return false;
    }
    if (!cJSON_AddStringToObject(root, key, value)) {
        return false;
    }

    return true;
}

void delete_item_from_json(cJSON* root , const char* key) {
    if (!root || !key) {
        return;
    }
    cJSON_DeleteItemFromObject(root , key);
}

cJSON* search_item_in_json(cJSON* root , const char* key) {
    if (root || !key) {
        return NULL;
    }

    return cJSON_GetObjectItem(root , key);
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

            }else if (strcmp(input, "exit") == 0) {

            }else if (strcmp(input , "add") == 0) {

            }else if (strcmp(input, "remove") == 0) {

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


