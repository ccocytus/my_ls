/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int n = 0;
    long nb = 0;
    int c = 1;

    while (str[n] == '-' || str[n] == '+') {
        if (str[n] == '-') {
            c *= -1;
        }
        n++;
    }
    while (str[n] != '\0') {
        if (str[n] < '0' || str[n] > '9')
            return (nb * c);
        nb = nb * 10 + (str[n] - 48);
        if (nb > 2147483647 || nb < -214783648) {
            return 0;
        }
        n++;
    }
    return (nb * c);
}
