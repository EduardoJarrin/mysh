/*
** EPITECH PROJECT, 2021
** CONVERSIONS
** File description:
** SE
*/

#include <stdlib.h>
#include "libmy.h"

unsigned long long int get_bin(int nb)
{
    unsigned long long int bin = 0;

    if (nb < 0)
        nb *= -1;
    for (; nb > 0; nb /= 2)
        bin = bin * 10 + nb % 2;
    return bin;
}

char *dec_to_bin(unsigned int dec)
{
    int len = 8 * sizeof(unsigned int);
    char *bin = my_strmalloc(len);

    while (dec > 0) {
        len--;
        bin[len] = dec % 2 + 48;
        dec /= 2;
    }
    while (*bin == '\0')
        bin++;
    return bin;
}

char *dec_to_oct(unsigned int dec)
{
    int len = 8 * sizeof(unsigned int);
    char *oct = my_strmalloc(len);

    while (dec > 0) {
        len--;
        oct[len] = dec % 8 + 48;
        dec /= 8;
    }
    while (*oct == '\0')
        oct++;
    return oct;
}
