/*
** EPITECH PROJECT, 2022
** my string format
** File description:
** SE
*/

#include "libmy.h"
#include <stdlib.h>

char *my_strstrip(char *str)
{
    int i = 0;

    while (*str == ' ')
        str++;
    i = my_strlen(str);
    while (str[--i] == ' ')
        str[i] = '\0';
    str = my_strdup(str);
    return str;
}

char *remove_extra_sep(char *str)
{
    int len = my_strlen(str);
    char *clean_str = my_strmalloc(len);
    int j = 0;

    if (!clean_str)
        return NULL;
    for (int i = 0; str[i]; j++) {
        for (; str[i] && str[i] != ' '; i++) {
            clean_str[j] = str[i];
            j++;
        }
        clean_str[j] = str[i];
        for (; str[i] && str[i] == ' '; i++);
    }
    free(str);
    return clean_str;
}

char *my_cleanstr(char *str)
{
    str = my_strstrip(str);
    str = remove_extra_sep(str);
    return str;
}
