/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
        count++;
    }
    return count;
}
