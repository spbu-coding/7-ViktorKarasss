//
// Created by mi on 18.11.2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "sortings.h"

void print_array(char **array, int str_count);

#define PUNCTUATION_MARKS_SIZE 6
static const char punctuation_marks[] = {'.', ',', ';', ':', '!', '?'};

char** array_string_malloc(int str_count){
    char **array = malloc(sizeof(char *) * str_count);
    for (int i = 0; i < str_count; i++)
        array[i] = malloc(sizeof(char) * MAX_INPUT_STRING_SIZE);
    return array;
}

void array_string_free(char** array, int str_count){
    for (int i = 0; i < str_count; i++) free(array[i]);
    free(array);
}

int comp_asc(const char *a, const char *b) {
    const unsigned char *s1 = (const unsigned char *) a;
    const unsigned char *s2 = (const unsigned char *) b;
    unsigned char c1, c2;
    do {
        c1 = (unsigned char) *s1++;
        c2 = (unsigned char) *s2++;
        if (c2 == '\0')
            return (c2 - c1) < 0;
    } while (c2 == c1);
    return (c2 - c1) < 0;
}

int is_in(char name, const char *name_list, int list_size) {
    int flag = 0;
    for (int i = 0; i < list_size; i++) {
        if (name == name_list[i])
            flag = 1;
    }
    return flag;
}

void clean(strings_array_t array, array_size_t size){
    char **buffer = array_string_malloc(size);
    for (int i = 0; i < size; i++) {
        char *str = malloc(sizeof(char) * MAX_INPUT_STRING_SIZE);
        int pos = 0;
        for (int j = 0; j < strlen(array[i]); j++) {
            if (!is_in(array[i][j], punctuation_marks, PUNCTUATION_MARKS_SIZE)) {
                str[pos] = array[i][j];
                pos++;
            }
        }
        buffer[i] = str;
    }
    for(int i = 0; i < size; i++){
        strcpy(array[i], buffer[i]);
    }
    array_string_free(buffer, size);
}

void sort(strings_array_t array, array_size_t size) {
    int location;
    char *new_element;
    for (int i = 1; i < size; i++) {
        new_element = array[i];
        location = i - 1;
        while (location >= 0 && strcmp(array[location], new_element) < 0) {
            array[location + 1] = array[location];
            location = location - 1;
        }
        array[location + 1] = new_element;
    }
}
