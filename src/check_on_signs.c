#include "../inc/header.h"

void check_on_signs(char *str, int line) {
    int counter_def = 0;
    int counter_coma = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') 
            counter_def++;
        if (str[i] == ',') 
            counter_coma++;
    }
    if (counter_def != 1 || counter_coma != 1) {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(++line));
        mx_printerr(" is not valid\n");
        exit(-5);
    }
}

