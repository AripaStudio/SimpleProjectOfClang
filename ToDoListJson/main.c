#include <stdio.h>
#include "JsonManagerClang.h"

int main(void) {
    const char* filename = "data.json";
    cJSON* root = NULL;

    root = create_or_load_json_file(filename);
    if (!root) {
        fprintf(stderr , "Failed to create or load JSON.\n");
        return 1;
    }

    return 0;
}