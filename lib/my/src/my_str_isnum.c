/*
** EPITECH PROJECT, 2022
** libmy
** File description:
** checks if str is a number
*/

#include <stdbool.h>
#include "libmy.h"

bool my_str_isnum(char const *str)
{
    int i = 0;

    if (!str)
        return false;
    if (str[i] == '-')
        i++;
    while (str[i] && char_is_num(str[i]))
        i++;
    if (str[i])
        return false;
    return true;
}
