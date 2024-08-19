/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** flags_md
*/

#include <stdarg.h>
#include "my.h"

int flags_md(va_list ap)
{
    int count = 0;

    my_putchar('%');
    count += 1;
    return count;
}
