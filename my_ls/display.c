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

void disp_reverse_order(struct fileinfo **f, int num)
{
    for (int i = num - 1; i >= 0; i--) {
        mini_printf("%s  ", f[i]->filename);
    }
    my_putchar('\n');
}

void disp_show_details(struct fileinfo **f, int num)
{
    for (int i = 0; i < num; i++) {
        mini_printf("%s\n", f[i]->filename);
    }
}

void disp_default(struct fileinfo **f, int num)
{
    for (int i = 0; i < num; i++) {
        mini_printf("%s  ", f[i]->filename);
    }
    my_putchar('\n');
}

void disp_file_names_helper(struct fileinfo **f, int num, struct option *op)
{
    if (op->reverseorder) {
        disp_reverse_order(f, num);
    } else {
        disp_show_details(f, num);
    }
}

void disp_file_names(struct fileinfo **f, int num, struct option *op)
{
    if (op->reverseorder || op->showdetails) {
        disp_file_names_helper(f, num, op);
    } else {
        disp_default(f, num);
    }
}
