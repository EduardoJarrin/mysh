/*
** EPITECH PROJECT, 2021
** MY_PUT_NBR
** File description:
** I dunno
*/

#include "libmy.h"

void my_putnbr_base(int nb, char *base)
{
    int bs = my_strlen(base);

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    if (nb <= bs) {
        my_putchar(base[nb]);
        return;
    }
    my_putnbr_base(nb / bs, base);
    my_putnbr_base(nb % bs, base);
}

static void printing_my_nbr(int nb)
{
    if (nb <= 9) {
        my_putchar(nb + 48);
        return;
    }
    printing_my_nbr(nb / 10);
    printing_my_nbr(nb % 10);
}

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    printing_my_nbr(nb);
}
