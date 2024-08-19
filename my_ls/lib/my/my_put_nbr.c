/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** my_put_nbr
*/

#include "my.h"

int negative(int number_put)
{
    int nbr;

    if (number_put < 0) {
        my_putchar('-');
        nbr = number_put * -1;
    } else {
        nbr = number_put;
    }
    return nbr;
}

int divide(int nbr)
{
    int div = 1;

    while (nbr > 9) {
        div *= 10;
        nbr /= 10;
    }
    return div;
}

int my_put_nbr(int number_put)
{
    int count = 0;
    int nbr = negative(number_put);
    int div = divide(nbr);

    while (div > 0) {
        my_putchar('0' + (nbr / div));
        nbr %= div;
        div /= 10;
        count++;
    }
    if (number_put < 0) {
        count++;
    }
    return count;
}
