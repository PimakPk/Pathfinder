#include "../inc/header.h"

void error_check(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    }

    int file_des = open(argv[1], O_RDONLY);
    if (file_des < 0)
    {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(-2);
    }

    int file_len = 0;
    char buf;
    while (read(file_des, &buf, 1))
        file_len++;
    if (file_len == 0)
    {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(-3);
    }
    close(file_des);

    file_des = open(argv[1], O_RDONLY);
    while (read(file_des, &buf, 1)) {
        if (buf == '\n') {
            break;
        }
        if (!mx_isdigit(buf)) {
            mx_printerr("error: line 1 is not valid\n");
            exit(-4);
        }
    }
    close(file_des);
}

