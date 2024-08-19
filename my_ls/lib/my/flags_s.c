/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** flags_s
*/

#include <stdarg.h>
#include "my.h"

int flags_s(va_list ap)
{
    int count = 0;

    count = my_putstr(va_arg(ap, char *));
    return count;
}
