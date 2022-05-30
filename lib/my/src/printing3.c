/*
** EPITECH PROJECT, 2021
** printing
** File description:
** SE
*/

#include <stdarg.h>
#include "libmy.h"

void printf_hex_u(va_list av)
{
    my_putnbr_base(va_arg(av, int), "0123456789ABCDEF");
}
