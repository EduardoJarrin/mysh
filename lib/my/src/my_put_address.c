/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** Prints chars
*/

#include "libmy.h"

void my_put_address(unsigned long nb)
{
    char *base = "0123456789abcdef";

    if (nb <= 16) {
        my_putchar(base[nb]);
        return;
    }
    my_put_address(nb / 16);
    my_put_address(nb % 16);
}
