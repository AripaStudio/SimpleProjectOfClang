//
// Created by VENUS on 7/6/2025.
//

#ifndef JSONMANAGERCLANG_H
#define JSONMANAGERCLANG_H

#include <stdbool.h>
#include "Cjson/cJSON.h"

cJSON* create_or_load_json_file(const char* filepath);

bool add_task_to_todolist(cJSON* root, const char* title, const char* description, const char* due_date, const char* status);

bool delete_item_from_json(cJSON* root , int id_to_delete);

cJSON* search_item_in_json(cJSON* root , int id_to_find);

void show_json_content(cJSON* root);

bool save_json_to_file(cJSON* root, const char* filepath);

void cleanup_json(cJSON* root);

bool MainMenu(const char* filename , cJSON* root);

void Show_Help();

void string_to_lower(char *str);

bool ConvertStringToIntAndCheck(const char* input, int* output);

#endif //JSONMANAGERCLANG_H


