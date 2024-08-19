/*
** EPITECH PROJECT, 2024
** my_ls.c
** File description:
** DIR
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

DIR *reopen_dir(const char *directoryname)
{
    DIR *dir = opendir(directoryname);

    if (dir == NULL) {
        perror("opendir");
        exit(84);
    }
    return dir;
}
