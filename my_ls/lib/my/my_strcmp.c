/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** int
*/

#include "my.h"

int my_strcmp(const char *string_1, const char *string_2)
{
    for (int i = 0; string_1[i] != '\0' || string_2[i] != '\0'; ++i) {
        if (string_1[i] > string_2[i]) {
            return string_1[i] - string_2[i];
        }
        if (string_1[i] < string_2[i]) {
            return string_1[i] - string_2[i];
        }
    }
    return 0;
}
