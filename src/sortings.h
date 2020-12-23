//
// Created by mi on 18.11.2020.
//

#ifndef HOMEWORK6_SORTINGS_H
#define HOMEWORK6_SORTINGS_H

#include <string.h>

#define  MAX_INPUT_STRING_SIZE 1000

typedef char** strings_array_t;
typedef size_t array_size_t;


void sort(strings_array_t, array_size_t);
void array_string_free(char** , int );
void clean(strings_array_t, array_size_t);
char** array_string_malloc(int);
#endif //HOMEWORK6_SORTINGS_H