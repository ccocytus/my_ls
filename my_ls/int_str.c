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

void int_to_string(long long value, char *str)
{
    int i = 0;
    int start;
    int end;
    char temp;

    do {
        str[i] = '0' + value % 10;
        i++;
        value /= 10;
    } while (value != 0);
    start = 0;
    end = i - 1;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    str[i] = '\0';
}

void processdet(struct option *op, struct fileinfo **f, int num, int total)
{
    char total_str[20];

    int_to_string((long long)total, total_str);
    mini_printf("total %s\n", total_str);
    if (op->reverseorder) {
        processo_rder(op, f, num);
    } else {
        process_order(op, f, num);
    }
}

void collec_f(struct option *op, struct fileinfo ***f, int *num, int *total)
{
    DIR *dir = opendir(op->directoryname);

    if (dir == NULL) {
        perror("opendir");
        exit(84);
    }
    count_files(op, dir, num, total);
    *f = (struct fileinfo **)malloc(*num * sizeof(struct fileinfo *));
    collect_fileinfo(op, dir, f);
    closedir(dir);
}

void processdir(struct option *op)
{
    struct fileinfo **f;
    int num = 0;
    int total = 0;

    if (op->showcurrdir && !op->showdetails) {
        mini_printf("%s\n", op->directoryname);
    } else {
        collec_f(op, &f, &num, &total);
        processf(op, f, num, total);
        for (int i = 0; i < num; i++) {
            free(f[i]->filename);
            free(f[i]);
        }
        free(f);
    }
}
