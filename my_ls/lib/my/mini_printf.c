/*
** EPITECH PROJECT, 2023
** mini_printf.c
** File description:
** int
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

int format_print(char arguments, va_list ap)
{
    switch (arguments) {
    case 'd' :
    my_put_nbr(va_arg(ap, int));
    break;
    case 'i':
    my_put_nbr(va_arg(ap, int));
    break;
    case 'c':
    my_putchar(va_arg(ap, int));
    break;
    case 's':
    my_putstr(va_arg(ap, char *));
    break;
    case '%':
    my_putchar('%');
    break;
    }
}

int mini_printf(const char *format, ...)
{
    int count = 0;
    va_list ap;

    va_start(ap, format);
    while (*format != '\0') {
        if (*format == '%') {
            ++format;
            count += format_print(*format, ap);
        } else {
            count += write(1, format, 1);
        }
        ++format;
    }
    va_end(ap);
    return count;
}
