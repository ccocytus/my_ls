/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** flags_bighex
*/

#include <stdarg.h>
#include "my.h"

int flags_bighex(va_list ap)
{
    int count = 0;

    count = my_putnbr_bighex(va_arg(ap, unsigned long));
    return count;
}
