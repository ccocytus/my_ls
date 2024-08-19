/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** flags_d
*/

#include <stdarg.h>
#include "my.h"

int flags_d(va_list ap)
{
    int count = 0;

    count = my_put_nbr(va_arg(ap, int));
    return count;
}
