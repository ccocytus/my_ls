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

void processf(struct option *op, struct fileinfo **f, int num, int total)
{
    char total_str[20];

    if (op->showcurrdir && op->showdetails) {
        processdet(op, f, num, total);
    } else {
        disp_f(op, f, num, total);
    }
}

void processo_rder(struct option *op, struct fileinfo **f, int num)
{
    for (int i = num - 1; i >= 0; i--) {
        printinfo(f[i]);
    }
}

void process_order(struct option *op, struct fileinfo **f, int num)
{
    for (int i = 0; i < num; i++) {
        printinfo(f[i]);
    }
}

void collect_fileinfo(struct option *op, DIR *dir, struct fileinfo ***f)
{
    struct dirent *entity;
    int index = 0;

    closedir(dir);
    dir = reopen_dir(op->directoryname);
    entity = readdir(dir);
    while (entity != NULL) {
        if (should_collect_file(op, entity)) {
            collect_in(op, entity, &((*f)[index]));
            index++;
        }
        entity = readdir(dir);
    }
}

int should_collect_file(struct option *op, struct dirent *entity)
{
    if (op->showhidden || entity->d_name[0] != '.') {
        if (!op->showcurrdir ||
        (op->showcurrdir && entity->d_type == DT_DIR)) {
            return 1;
        }
    }
    return 0;
}
