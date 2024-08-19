/*
** EPITECH PROJECT, 2023
** my_ls.c
** File description:
** int
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "include/my.h"
#include "include/struct.h"

void check_flag(char option, struct option *op)
{
    switch (option) {
    case 'a':
        op->showhidden = 1;
        break;
    case 'r':
        op->reverseorder = 1;
        break;
    case 'd':
        op->showcurrdir = 1;
        break;
    case 'l':
        op->showdetails = 1;
        break;
    case 't':
        op->sort_time = 1;
        break;
    default:
        mini_printf("not option\n");
        exit(84);
    }
}

void option_s(int argc, char **argv, struct option *op, int i)
{
    if (argv[i][0] == '-') {
        for (int j = 1; argv[i][j] != '\0'; j++) {
            check_flag(argv[i][j], op);
            }
        } else {
            op->directoryname = argv[i];
        }
}

void disp_file_details(struct fileinfo **f, int num, struct option *op)
{
    if (op->reverseorder) {
        for (int i = num - 1; i >= 0; i--) {
            printinfo(f[i]);
        }
    } else {
        for (int i = 0; i < num; i++) {
            printinfo(f[i]);
        }
    }
}

void disp_f(struct option *op, struct fileinfo **f, int num, int total)
{
    char total_str[20];

    total /= 2;
    if (op->showdetails) {
        int_to_string((long long)total, total_str);
        mini_printf("total %s\n", total_str);
        disp_file_details(f, num, op);
    } else {
        disp_file_names(f, num, op);
    }
}
