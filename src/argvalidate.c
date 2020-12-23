//
// Created by mi on 18.11.2020.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "argvalidate.h"

#define ARG_FILE_NAME 1
#define  ARGS_COUNT 2

#define MAX_INPUT_STRING_SIZE 1000

#define errprintf(x) fprintf(stderr, "%s", x)

int count_str(char* file_name) {
    FILE* file = fopen(file_name, "r");
    int count_of_input_strings = 0;
    char *input_string = malloc(sizeof(char) * MAX_INPUT_STRING_SIZE);
    while(!feof(file)){
        if(fgets(input_string, MAX_INPUT_STRING_SIZE, file) != NULL){
            count_of_input_strings++;
        }
    }
    free(input_string);
    fclose(file);

    return count_of_input_strings;
}

int validate(int argc, char **argv) {
    if (argc != ARGS_COUNT) {
        errprintf("Incorrect count of argument");
        return -1;
    }

    FILE *file;
    file = fopen(argv[ARG_FILE_NAME], "r");
    if (file == NULL) {
        errprintf("Incorrect file name or file can not be open");
        return -1;
    }
    fclose(file);
    return 0;
}