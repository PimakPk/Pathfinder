#include "../inc/header.h"

void free_lists_isl(t_island **list_islands) {
    if (*list_islands == NULL) return;
    t_island *temp_isl = *list_islands;
    while (temp_isl -> next -> next) 
        temp_isl = temp_isl -> next;
    free(temp_isl -> next);
    temp_isl -> next = NULL;
    temp_isl = NULL;
}

void free_lists_path(t_path **list_path) {
    if (*list_path == NULL) return;
    t_path *temp_path = *list_path;
    while (temp_path -> next -> next) 
        temp_path = temp_path -> next;
    free(temp_path -> next);
    temp_path -> next = NULL;
    temp_path = NULL;
}

