/*
** EPITECH PROJECT, 2021
** MY_GETNBR
** File description:
** Number
*/

#include "libmy.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int sign = 1;

    for (int i = 0; str[i] == '+' || str[i] == '-'; i++)
        if (str[i] == '-')
            sign *= -1;
    for (int i = 0; str[i] && char_is_num(str[i]); i++)
        nb = nb * 10 + (str[i] - '0');
    return nb * sign;
}
