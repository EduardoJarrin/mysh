/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** concatenates two strings
*/

#include "libmy.h"

char *my_strcat(char *dest, char const *src)
{
    char *new = my_strmalloc(my_strlen(dest) + my_strlen(src));
    int i = 0;
    int j = 0;

    while (dest[i]) {
        new[i] = dest[i];
        i++;
    }
    while (src[j]) {
        new[i] = src[j];
        i++;
        j++;
    }
    return new;
}

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int size = my_strlen(dest);

    while (src[i] != '\0' && i < nb) {
        dest[size + i] = src[i];
        i++;
    }
    dest[size + i] = '\0';
    return (dest);
}

char *my_strconcat(char *dest, char const *src)
{
    int i = 0;
    int size = my_strlen(dest);

    while (src[i] != '\0') {
        dest[size + i] = src[i];
        i++;
    }
    dest[size + i] = '\0';
    return (dest);
}
