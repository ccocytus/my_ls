/*
** EPITECH PROJECT, 2023
** My_printf.c
** File description:
** int
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "../../include/my.h"
#include "../../include/struct.h"
#include <stdio.h>

const flag_t flag[11] = {
    { 'c', &flags_c },
    { 's', &flags_s },
    { 'd', &flags_d },
    { 'i', &flags_i },
    { '%', &flags_md },
    { 'o', &flags_o },
    { 'x', &flags_x },
    { 'X', &flags_bighex },
    { 'u', &flags_u },
    { 'p', &flags_p },
    { 'f', &flags_f }
};

int check_flags(va_list ap, int *i, char c, int *counter)
{
    for (int index = 0; index < 11; index++) {
        if (c == flag[index].flag) {
            *counter += flag[index].ptr_function(ap);
            (*i)++;
            return 0;
        }
    }
    return -1;
}

int handle_flags_and_space(va_list ap, int *i, const char *format, int *count)
{
    int j = *i + 1;
    int flag_processed = 0;

    if (check_flags(ap, &j, format[j], count) == 0) {
        flag_processed = 1;
    } else {
        *count += my_putchar('%');
    }
    if (flag_processed) {
        if (format[j] != ' ' && format[j] != '\n' && format[j] != '\0') {
            *count += my_putchar(' ');
        }
    }
    *i = j - 1;
}

int line(va_list ap, int *i, char *format, int *counter)
{
    int *stock;

    if (format[*i + 1] == 'n') {
        stock = va_arg(ap, int *);
        *stock = *counter;
        (*i) += 2;
    } else {
        handle_flags_and_space(ap, i, format, counter);
    }
}

int my_printf(const char *format, ...)
{
    va_list ap;
    int counter = 0;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            line(ap, &i, format, &counter);
        } else {
            counter += my_putchar(format[i]);
        }
    }
    va_end(ap);
    return counter;
}
