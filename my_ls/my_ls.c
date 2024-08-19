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

int main(int argc, char **argv)
{
    struct option op = { ".", 0, 0, 0, 0 };

    option(argc, argv, &op);
    processdir(&op);
    return 0;
}

char *getusername(struct stat *filestat)
{
    struct passwd *pw = getpwuid(filestat->st_uid);

    return (pw != NULL) ? pw->pw_name : "unknown";
}

char *getgroupname(struct stat *filestat)
{
    struct group *gr = getgrgid(filestat->st_gid);

    return (gr != NULL) ? gr->gr_name : "unknown";
}
