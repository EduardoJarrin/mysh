/*
** EPITECH PROJECT, 2021
** my_strup
** File description:
** allocates memory and copies the string given as argument
*/

#include "libmy.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *str = my_strmalloc(len);

    if (!str)
        return str;
    for (int i = 0; i < len; i++)
        str[i] = src[i];
    str[len] = '\0';
    return str;
}

char **my_arrdup(char **src)
{
    int len = my_arrlen(src);
    char **arr = my_arrmalloc(len + 1);

    if (!arr)
        return arr;
    for (int i = 0; i < len; i++)
        arr[i] = my_strdup(src[i]);
    arr[len] = NULL;
    return arr;
}
