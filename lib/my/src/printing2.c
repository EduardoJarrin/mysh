/*
** EPITECH PROJECT, 2021
** MY_PRINTF
** File description:
** SE
*/

#include <stdarg.h>
#include "libmy.h"

void printf_address(va_list av)
{
    void *address = va_arg(av, void *);

    my_putstr("0x");
    my_putaddress((unsigned long)address);
}

void printf_bin(va_list av)
{
    my_putstr(dec_to_bin(va_arg(av, unsigned int)));
}

void printf_hex_l(va_list av)
{
    my_putnbr_base(va_arg(av, int), "0123456789abcdef");
}

void printf_per(va_list av)
{
    (void)av;
    my_putchar('%');
}

void printf_uint(va_list av)
{
    my_putnbr_base(va_arg(av, unsigned int), "0123456789");
}
