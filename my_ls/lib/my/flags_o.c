/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** flags_o
*/

#include <stdarg.h>
#include "my.h"

int flags_o(va_list ap)
{
    int count = 0;

    count = my_putnbr_octal(va_arg(ap, int));
    return count;
}
