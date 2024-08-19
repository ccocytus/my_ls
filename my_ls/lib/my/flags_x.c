/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** flags_x
*/

#include "my.h"
#include <stdarg.h>

int flags_x(va_list ap)
{
    int count = 0;

    count = my_putnbr_hex(va_arg(ap, unsigned long));
    return count;
}
