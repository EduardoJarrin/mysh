/*
** EPITECH PROJECT, 2021
** MY_PRINTF
** File description:
** SE
*/

#include <stdarg.h>
#include "libmy.h"
#include "my_printf.h"

cases_t cases[] = {
    {'p', &printf_address},
    {'c', &printf_char},
    {'b', &printf_bin},
    {'x', &printf_hex_l},
    {'X', &printf_hex_u},
    {'d', &printf_int},
    {'i', &printf_int},
    {'o', &printf_oct},
    {'s', &printf_str},
    {'%', &printf_per},
    {'u', &printf_uint}
};

void switches(va_list av, char *format)
{
    for (int i = 0; i < 12; i++)
        if (*format == cases[i].flag)
            cases[i].f(av);
}

void my_printf(char *format, ...)
{
    va_list av;

    va_start(av, format);
    while (*format != '\0') {
        for (; *format == '%'; format++)
            switches(av, ++format);
        if (*format != '\0') {
            my_putchar(*format);
            format++;
        }
    }
    va_end(av);
}
