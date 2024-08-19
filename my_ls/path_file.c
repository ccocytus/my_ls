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

char *getfilepath(struct option *op, const char *filename)
{
    static char filepath[MAX_PATH_LEN];

    my_strcpy(filepath, op->directoryname);
    if (filepath[my_strlen(filepath) - 1] != '/') {
        my_strcat(filepath, "/");
    }
    my_strcat(filepath, filename);
    return filepath;
}

void process_e(struct option *p, struct dirent *entity, int *num, int *total)
{
    struct stat filestat;
    char *filepath;

    if (!entity_process(p, entity)) {
        return;
    }
    (*num)++;
    filepath = getfilepath(p, entity->d_name);
    if (stat(filepath, &filestat) == -1) {
        perror("stat");
        exit(84);
    }
    *total += filestat.st_blocks;
}

void collect_in(struct option *o, struct dirent *entity, struct fileinfo **f)
{
    char *filepath;

    (*f) = (struct fileinfo *)malloc(sizeof(struct fileinfo));
    filepath = getfilepath(o, entity->d_name);
    if (stat(filepath, &(*f)->filestat) == -1) {
        perror("stat");
        exit(1);
    }
    (*f)->filename = my_strdup(entity->d_name);
}

void disp_ds(struct option *op, struct fileinfo **f, int num)
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

void disp_d(struct option *op, struct fileinfo **f, int num, int total)
{
    char total_str[20];

    total /= 2;
    if (op->showcurrdir && op->showdetails) {
        int_to_string((long long)total, total_str);
        mini_printf("total %s\n", total_str);
        disp_ds(op, f, num);
    } else {
        disp_f(op, f, num, total);
        freedirectory(f, num);
    }
}
