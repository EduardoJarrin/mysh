/*
** EPITECH PROJECT, 2021
** MY_PRINTF
** File description:
** SE
*/

#include <stdarg.h>
#include "libmy.h"

void printf_char(va_list av)
{
    my_putchar((char)va_arg(av, int));
}

void printf_int(va_list av)
{
    my_putnbr(va_arg(av, int));
}

void printf_str(va_list av)
{
    my_putstr(va_arg(av, char *));
}

void printf_oct(va_list av)
{
    my_putstr(dec_to_oct(va_arg(av, unsigned int)));
}
