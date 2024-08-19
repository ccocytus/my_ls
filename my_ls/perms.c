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

void printperm(struct stat *filestat)
{
    mini_printf((S_ISDIR(filestat->st_mode)) ? "d" : "-");
    mini_printf((filestat->st_mode & S_IRUSR) ? "r" : "-");
    mini_printf((filestat->st_mode & S_IWUSR) ? "w" : "-");
    mini_printf((filestat->st_mode & S_IXUSR) ? "x" : "-");
    mini_printf((filestat->st_mode & S_IRGRP) ? "r" : "-");
    mini_printf((filestat->st_mode & S_IWGRP) ? "w" : "-");
    mini_printf((filestat->st_mode & S_IXGRP) ? "x" : "-");
    mini_printf((filestat->st_mode & S_IROTH) ? "r" : "-");
    mini_printf((filestat->st_mode & S_IWOTH) ? "w" : "-");
    mini_printf((filestat->st_mode & S_IXOTH) ? "x" : "-");
    mini_printf(". ");
}

void printinfo(struct fileinfo *fileinfo)
{
    char *username = getusername(&fileinfo->filestat);
    char *groupname = getgroupname(&fileinfo->filestat);
    char nlink_str[20];
    char size_str[20];
    char *d;

    printperm(&fileinfo->filestat);
    int_to_string((long long)fileinfo->filestat.st_nlink, nlink_str);
    mini_printf("%s ", nlink_str);
    mini_printf("%s %s ", username, groupname);
    int_to_string((long long)fileinfo->filestat.st_size, size_str);
    mini_printf("%s ", size_str);
    d = ctime(&(fileinfo->filestat.st_mtime));
    d += 4;
    d[my_strlen(d)-9] = '\0';
    mini_printf("%s ", d);
    mini_printf("%s\n", fileinfo->filename);
}

void printdirinfo(struct option *op)
{
    struct stat dirStat;
    char size_str[20];
    char *date;

    if (stat(op->directoryname, &dirStat) == -1) {
        perror("stat");
        exit(84);
    }
    printperm(&dirStat);
    mini_printf("%d ", (int)dirStat.st_nlink);
    mini_printf("%s %s ", getusername(&dirStat), getgroupname(&dirStat));
    int_to_string((long long)dirStat.st_size, size_str);
    mini_printf("%s ", size_str);
    date = ctime(&(dirStat.st_mtime));
    date += 4;
    date[my_strlen(date)-9] = '\0';
    mini_printf("%s ", date);
    mini_printf("%s\n", op->directoryname);
}
