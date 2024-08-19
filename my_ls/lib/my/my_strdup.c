/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** the first
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *copy_str;

    copy_str = malloc(my_strlen(src) + 1);
    if (copy_str == NULL) {
        perror("malloc");
        exit(84);
    }
    my_strcpy(copy_str, src);
    return copy_str;
}
