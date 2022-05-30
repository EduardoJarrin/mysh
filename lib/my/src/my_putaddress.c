/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** Prints chars
*/

#include <unistd.h>

void my_putaddress(unsigned long nb)
{
    char *base = "0123456789abcdef";

    if (nb <= 15) {
        write(1, &base[nb], 1);
        return;
    }
    my_putaddress(nb / 16);
    my_putaddress(nb % 16);
}
