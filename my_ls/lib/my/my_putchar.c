/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** my_putchar
*/

#include <unistd.h>
#include "my.h"

int my_putchar(char c)
{
    write(1, &c, 1);
}
