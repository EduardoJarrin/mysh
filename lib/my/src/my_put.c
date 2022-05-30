/*
** EPITECH PROJECT, 2021
** My_putstr
** File description:
** Prints string
*/

#include <unistd.h>
#include "libmy.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    if (!str)
        return;
    write(1, str, my_strlen(str));
}

void my_putarr(char **arr, char *sep)
{
    for (int i = 0; arr[i]; i++) {
        my_putstr(arr[i]);
        my_putstr(sep);
    }
}

void my_perror(char const *str)
{
    if (!str)
        return;
    write(2, str, my_strlen(str));
}
