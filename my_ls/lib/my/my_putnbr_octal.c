/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** my_putnbr_octal
*/

#include "my.h"

int my_putnbr_octal(unsigned int nb)
{
    int count = 0;
    char o[] = "012345678";
    char buff[10];
    int i = 0;

    while (nb > 0) {
        buff[i] = o[nb % 8];
        nb /= 8;
        i++;
    }
    if (i == 0) {
        my_putchar('0');
        count++;
    } else {
        for (i--; i >= 0; i--) {
            my_putchar(buff[i]);
            count++;
        }
    }
    return count;
}
