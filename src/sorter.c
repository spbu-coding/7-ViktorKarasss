#include <stdio.h>

#include "sortings.h"
#include "argvalidate.h"
#include "file_handler.h"


#define MAX_INPUT_STRING_SIZE 1000
#define ARG_FILE_NAME 1


void print_array(char **array, int str_count){
    if(str_count > 100)
        str_count = 100;
    for(int i = 0; i < str_count; i++){
        printf("%s",array[i]);
    }
}

int main(int argc, char **argv) {
    int code = validate(argc, argv);
    if (code == -1)
        return code;
    char *file_name = argv[ARG_FILE_NAME];
    int str_count = count_str(file_name);

    FILE *file_r = fopen(file_name, "r");
    char **array = array_string_malloc(str_count);
    read(file_r, array, str_count);
    fclose(file_r);

    clean(array,str_count);
    sort(array,str_count);
    print_array(array,str_count);

    FILE *file_w = fopen(file_name, "w");
    write(file_w, array, str_count);
    array_string_free(array,str_count);
    fclose(file_w);

    return 0;
}
