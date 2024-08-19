/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** flags_f
*/

#include <stdarg.h>
#include "my.h"

int flags_f(va_list ap)
{
    int count = 0;

    count = my_putnbr_float(va_arg(ap, double));
    return count;
}
