#ifndef HEADER_H
#define HEADER_H

#include "libmx.h"
#include <stdio.h>
#include <limits.h>

typedef struct s_path {
    int index1;
    int index2;
    int bridge;
    struct s_path *next;
}               t_path;

typedef struct s_island {
    char *name;
    int id;
    struct s_island *next;
}               t_island;

void error_check(int argc, char *argv[]);
void check_on_valid_str(char *str, int line);
void check_on_valid_bridge(char *str, int line);
void check_on_signs(char *str, int line);
char **str_to_arr_isl(char *str);
void mx_push_back_isl(t_island **list, int id, char *name);
t_island *fill_names(char **arr_res, int size);
t_path *fill_path(t_island *list_isl, char **arr_res);
int **fill_array(t_path *list, int size);
void algoritm(int **arr, int size, t_island *list_isl);
void free_lists_isl(t_island **list_islands);
void free_lists_path(t_path **list_path);

#endif

