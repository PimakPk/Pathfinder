#include "../inc/header.h"

int main(int argc, char* argv[]) {
    error_check(argc, argv);
    int size;
    char *file = mx_file_to_str(argv[1]);
    size = mx_atoi(file);
    char **str = str_to_arr_isl(file);
    t_island *list_islands_name = fill_names(str, size);
    t_path *list_path = fill_path(list_islands_name, str);
    int **arr = fill_array(list_path, size);
    algoritm(arr, size, list_islands_name);
    //free data
    mx_del_strarr(&str);
    mx_strdel(&file);
    free_lists_isl(&list_islands_name);
    free_lists_path(&list_path);
}

