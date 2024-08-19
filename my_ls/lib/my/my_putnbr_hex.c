/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** my_putnbr_hex
*/

#include "my.h"

int my_putnbr_hex(unsigned int nb)
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
        count++;
    } else {
        for (i--; i >= 0; i--) {
            my_putchar(buff[i]);
            count++;
        }
    }
    return count;
}
