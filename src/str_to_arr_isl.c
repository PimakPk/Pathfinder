#include "../inc/header.h"

char **str_to_arr_isl(char *str) {
    int lines = 0;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            lines++;
        }
        i++;
    }

    int size = mx_atoi(str);

    char **arr_res = (char **) malloc((3 * lines + 1) * sizeof(char *));
    for (int i = 0; i < size; i++) {
        arr_res[i] = NULL;
    }

    char **arr_str = mx_strsplit(str, '\n');

    int counter = 0;
    for (int i = 1; arr_str[i] != NULL; i++) {
        char *temp = mx_strtrim(arr_str[i]);
        check_on_signs(temp, i);
        char **temp_arr = mx_strsplit(temp, '-');

        check_on_valid_str(temp_arr[0], i);
        arr_res[counter] = temp_arr[0];
        counter++;
        arr_res[counter] = mx_strdup(mx_strsplit(temp_arr[1], ',')[0]);
        check_on_valid_str(arr_res[counter], i);
        if (mx_strcmp(arr_res[counter], arr_res[counter - 1]) == 0) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(i + 1));
            mx_printerr(" is not valid\n");
            exit(-5);
        }
        counter++;
        arr_res[counter] = mx_strdup(mx_strsplit(temp_arr[1], ',')[1]);
        check_on_valid_bridge(arr_res[counter], i);
        counter++;
    }

    //check on dubl bridges
    for (int i = 0; arr_res[i] != NULL; i += 3) {
        for (int j = i + 3; arr_res[j] != NULL; j += 3) {
            if (mx_strcmp(arr_res[i], arr_res[j]) == 0 && mx_strcmp(arr_res[i + 1], arr_res[j + 1]) == 0) {
                mx_printerr("error: duplicate bridges\n");
                exit(-7);
            }
        }
    }

    return arr_res;
}

