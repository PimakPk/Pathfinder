#include "../inc/header.h"

t_path *mx_create_node_path(int index1, int index2, int bridge) {
    t_path *newNode = (t_path*)malloc(sizeof(t_path));
    newNode -> next = NULL;
    newNode -> index1 = index1;
    newNode -> index2 = index2;
    newNode -> bridge = bridge;
    return newNode;
}

void mx_push_back_path(t_path **list, int index1, int index2, int bridge) {
    if (!*list) {
        *list = mx_create_node_path(index1, index2, bridge);
        return;
    }
    t_path *temp = *list;
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> next = mx_create_node_path(index1, index2, bridge);
}

t_path *fill_path(t_island *list_isl, char **arr_res) {
    t_island *list_isl_start = list_isl;
    t_path *list_path = mx_create_node_path(0, 1, mx_atoi(arr_res[2]));
    int counter = 3;
    while (arr_res[counter]) {
        while(mx_strcmp(list_isl -> name, arr_res[counter]) != 0) {
            list_isl = list_isl -> next;
        }
        int temp_index1 = list_isl -> id;
        list_isl = list_isl_start;
        counter++;
        while(mx_strcmp(list_isl -> name, arr_res[counter]) != 0) {
            list_isl = list_isl -> next;
        }
        int temp_index2 = list_isl -> id;
        list_isl = list_isl_start;
        counter++;
        mx_push_back_path(&list_path, temp_index1, temp_index2, mx_atoi(arr_res[counter]));
        counter++;
    }

    //check on INT_MAX
    long long sum = 0;
    t_path * list_path_start = list_path;
    while (list_path != NULL) {
        sum += list_path -> bridge;
        list_path = list_path -> next;
    }
    if (sum > INT_MAX) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        exit(-8);
    }
    list_path = list_path_start;
    return list_path;
}

