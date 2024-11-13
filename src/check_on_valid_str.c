#include "../inc/header.h"

void check_on_valid_str(char *str, int line) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!mx_isalpha(str[i])) {
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(++line));
            mx_printerr(" is not valid\n");
            exit(-5);
        }
    }
}

