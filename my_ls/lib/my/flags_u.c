/*
** EPITECH PROJECT, 2023
** Main Lib
** File description:
** flags_u
*/

#include <stdarg.h>
#include "my.h"

int flags_u(va_list ap)
{
    int count = 0;

    count = my_putnbr_u(va_arg(ap, int));
    return count;
}
