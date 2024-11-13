#include "../inc/header.h"

void algoritm(int **arr, int size, t_island *list_isl) {
    t_island *list_isl_start = list_isl;
    t_island *list_isl_start_i = list_isl;
    t_island *list_isl_start_j = list_isl;
    int **arr_sec = (int **)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        arr_sec[i] = (int *)malloc(size * sizeof(int));
    }

     for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr_sec[i][j] = -1;
        }
     }

    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (arr[i][j] > (arr[i][k] + arr[k][j])) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                    arr_sec[i][j] = k;
                }
            }
        }
    }

    //OUTPUT
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            for (int l = 0; l < j; l++) {
                list_isl_start_j = list_isl_start_j -> next;
            }
            mx_printstr("========================================\n");
            //Path
            mx_printstr("Path: ");
            mx_printstr(list_isl_start_i -> name);
            mx_printstr(" -> ");
            mx_printstr(list_isl_start_j -> name);
            mx_printstr("\n");
            //Route
            mx_printstr("Route: ");
            mx_printstr(list_isl_start_i -> name);
            mx_printstr(" -> ");
            int temp_i = i;
            int temp_j = j;
            while (arr[temp_i][temp_j] != 0) {
                if (arr_sec[temp_i][temp_j] == -1) {
                    break;
                }
                while (arr_sec[temp_i][temp_j] != -1) {
                    temp_j = arr_sec[temp_i][temp_j];
                }
                for (int k = 0; k < temp_j; k++) {
                    list_isl = list_isl -> next;
                }
                mx_printstr(list_isl -> name);
                mx_printstr(" -> ");
                list_isl = list_isl_start;
                temp_i = temp_j;
                temp_j = j;
            }
            mx_printstr(list_isl_start_j -> name);
            mx_printstr("\n");
            //Distance
            mx_printstr("Distance: ");
            if (arr_sec[i][j] == -1) {
                mx_printint(arr[i][j]);
                mx_printstr("\n");

                mx_printstr("========================================\n");
            }
            else {
                int temp_i = i;
                int temp_j = j;
                while (arr[temp_i][temp_j] != 0) {
                    while (arr_sec[temp_i][temp_j] != -1) {
                        temp_j = arr_sec[temp_i][temp_j];
                    }
                    mx_printint(arr[temp_i][temp_j]);
                    temp_i = temp_j;
                    temp_j = j;
                    if (arr[temp_i][temp_j] != 0)
                        mx_printstr(" + ");
                }
                mx_printstr(" = ");
                mx_printint(arr[i][j]);
                mx_printstr("\n");

                mx_printstr("========================================\n");
            }
            //end  cukl
            list_isl_start_j = list_isl_start;
        }
        list_isl_start_i = list_isl_start_i -> next;
        //list_isl_start_j = list_isl_start;
    }

    //clean memmory
    for (int i = 0; i < size; i++) {
        free(arr[i]);
        free(arr_sec[i]);
    }
    free(arr);
    free(arr_sec);
    return;
}

