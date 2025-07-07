//
// Created by VENUS on 7/6/2025.
//

#include "JsonManagerClang.h"
#include "Cjson/cJSON.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

cJSON* create_or_load_json_file(const char *filepath)
{
    FILE* fp = NULL;
    long file_size = 0;
    char* data = NULL;
    cJSON* root = NULL;

    fp = fopen(filepath, "rb");
    if (fp) {
        fseek (fp, 0, SEEK_END);
        file_size = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        data = (char*)malloc(file_size + 1);
        if (data) {
            fread(data, 1, file_size, fp);
            data[file_size] = '\0';
            root = cJSON_Parse(data);
            free(data);
        }
        fclose(fp);
    }

    if (!root) {
        root = cJSON_CreateObject();
    }
    return root;
}
void cleanup_json(cJSON* root) {
    if (root) {
        cJSON_Delete(root);
        printf("JSON memory cleaned up. \n");
    }
}
