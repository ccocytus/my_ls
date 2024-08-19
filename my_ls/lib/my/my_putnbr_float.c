/*
** EPITECH PROJECT, 2023
** Main Lib
** File description:
** my_putnbr_float
*/

#include "my.h"

int my_putnbr_float(double number_put)
{
    int count = 0;
    int int_part = (int)number_put;
    double decimal_part = number_put - int_part;
    int decimal_places = 6;
    int digit = 0;

    count = my_put_nbr(int_part);
    my_putchar('.');
    count += 1;
    for (int i = 0; i < decimal_places; i++) {
        decimal_part *= 10;
        digit = (int)decimal_part;
        my_putchar('0' + digit);
        count ++;
        decimal_part -= digit;
    }
    return count;
}
