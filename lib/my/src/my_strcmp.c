/*
** EPITECH PROJECT, 2021
** MY_STRNCMP
** File description:
** Compares the size of two strings
*/

#include <stddef.h>
#include <limits.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return INT_MIN;
    for (; (s1[i] && s2[i]) && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return INT_MIN;
    for (; i < n - 1 && ((s1[i] && s2[i]) && s1[i] == s2[i]); i++);
    return (s1[i] - s2[i]);
}
