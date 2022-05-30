/*
** EPITECH PROJECT, 2021
** MY_STRCPY
** File description:
** Copies the content of a string
*/

#include "libmy.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
