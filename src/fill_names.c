#include "../inc/header.h"

t_island *mx_create_node_isl(int id, char *name) {
    t_island *newNode = (t_island*)malloc(sizeof(t_island));
    newNode -> next = NULL;
    newNode -> id = id;
    newNode -> name = name;
    return newNode;
}

void mx_push_back_isl(t_island **list, int id, char *name) {
    if (!*list) {
        *list = mx_create_node_isl(id, name);
        return;
    }
    t_island *temp = *list;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = mx_create_node_isl(id, name);
}

t_island *fill_names(char **arr_res, int size) {
    int id_counter = 0;
    t_island *list_isl = mx_create_node_isl(id_counter, arr_res[0]);
    id_counter++;
    bool dup = false;
    t_island *list_isl_start = list_isl;

    for (int i = 1; arr_res[i] != NULL; i++) {
        dup = false;
        if (mx_isdigit(arr_res[i][0])) {
            continue;
        }
        for (int j = 0; j < i; j++) {
            if (mx_strcmp(arr_res[i], arr_res[j]) == 0) {
                dup = true;
                break;
            }
        }
        if (!dup) {
            /*if (id_counter >= size - 1) {
                mx_printerr("error: invalid number of islands\n");
                exit(-6);
            }*/
            mx_push_back_isl(&list_isl_start, id_counter, arr_res[i]);
            id_counter++;
        }
    }
    if (id_counter != size) {
        mx_printerr("error: invalid number of islands\n");
        exit(-6);
    }
    return list_isl_start;
}

