/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** my_putstr_error
*/

#include <unistd.h>
#include "my.h"

int my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(2, &str[i], 1);
        i++;
    }
}
