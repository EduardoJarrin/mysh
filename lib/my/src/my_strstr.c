/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** finds a string inside other string
*/

#include "libmy.h"
#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int len1 = my_strlen(str);
    int len2 = my_strlen(to_find);

    for (int i = 0; i + len2 <= len1; i++)
        if (!my_strncmp(str + i, to_find, len2))
            return str + i;
    return NULL;
}
