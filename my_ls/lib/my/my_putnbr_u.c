/*
** EPITECH PROJECT, 2023
** Main Lib
** File description:
** my_putnbr_u
*/

#include "my.h"

int my_putnbr_u(unsigned int nb)
{
    int count = 0;
    char u[] = "0123456789";
    char buff[10];
    int i = 0;

    while (nb > 0) {
        buff[i] = u[nb % 10];
        nb /= 10;
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
