/*
** EPITECH PROJECT, 2021
** MY_STR_ISALPHA
** File description:
** Returns 1 if its characters are letter
*/

#include "libmy.h"

bool my_str_isalphanum(char const *str)
{
    if (!str)
        return false;
    for (int i = 0; str[i]; i++)
        if (!char_is_alphanum(str[i]))
            return false;
    return true;
}
