/*
** EPITECH PROJECT, 2023
** flags_p.c
** File description:
** void
*/

#include <stdarg.h>
#include "my.h"

int my_putnbr_hex_long(unsigned long nb)
{
    int count = 0;
    char hexa[] = "0123456789abcdef";
    char buff[10];
    int i = 0;

    while (nb > 0) {
        buff[i] = hexa[nb % 16];
        nb /= 16;
        i++;
    }
    if (i == 0) {
        my_putchar('0');
        count ++;
    } else {
        for (i--; i >= 0; i--) {
            my_putchar(buff[i]);
            count++;
        }
    }
    return count;
}

int flags_p(va_list ap)
{
    void *ptr = va_arg(ap, void *);
    int count = 0;

    my_putchar('0');
    my_putchar('x');
    count += 2;
    count += my_putnbr_hex_long((unsigned long)ptr);
    return count;
}
