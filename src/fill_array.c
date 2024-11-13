#include "../inc/header.h"

int **fill_array(t_path *list, int size) {
    t_path *list_path_start = list;
    int max_sum = 0;
    while (list_path_start != NULL) {
        max_sum += list_path_start -> bridge;
        list_path_start = list_path_start -> next;
    }
    int **arr = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        arr[i] = (int *)malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = max_sum;
        }
    }
    for (int i = 0; i < size; i++) {
        arr[i][i] = 0;
    }
    t_path *temp = list;
    while (temp != NULL) {
        arr[temp -> index1][temp -> index2] = temp -> bridge;
        arr[temp -> index2][temp -> index1] = temp -> bridge;
        temp = temp -> next;
    }
    return arr;
}

