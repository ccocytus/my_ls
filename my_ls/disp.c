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

void option(int argc, char **argv, struct option *op)
{
    for (int i = 1; i < argc; i++) {
        option_s(argc, argv, op, i);
    }
}

void freedirectory(struct fileinfo **f, int num)
{
    for (int i = 0; i < num; i++) {
        free(f[i]->filename);
        free(f[i]);
    }
    free(f);
}

int entity_process(struct option *p, struct dirent *entity)
{
    if (p->showhidden || entity->d_name[0] != '.') {
        if (!p->showcurrdir || (p->showcurrdir && entity->d_type == DT_DIR)) {
            return 1;
        }
    }
    return 0;
}

void count_files(struct option *op, DIR *dir, int *num, int *total)
{
    struct dirent *entity = readdir(dir);

    while (entity != NULL) {
        process_e(op, entity, num, total);
        entity = readdir(dir);
    }
}
