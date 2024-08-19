/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** flags_c
*/

#include <stdarg.h>
#include "my.h"

int flags_c(va_list ap)
{
    int count = 0;

    my_putchar(va_arg(ap, int));
    count++;
    return count;
}
