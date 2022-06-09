/*
** EPITECH PROJECT, 2021
** Clean check_malloc
** File description:
** Clean check_malloc
*/

#include <stdlib.h>
#include "libmy.h"

void free_arr(char **arr)
{
    if (!arr)
        return;
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

void *check_malloc(size_t size)
{
    void *ptr = NULL;

    if (size <= 0) {
        my_perror("Invalid malloc size\n");
        return NULL;
    }
    if (!(ptr = malloc(size)))
        my_perror("Could not allocate memory\n");
    return ptr;
}

char *my_strmalloc(int len)
{
    char *str = check_malloc(len + 1);

    if (!str)
        return NULL;
    for (int i = 0; i <= len; i++)
        str[i] = '\0';
    return str;
}

char **my_arrmalloc(int len)
{
    char **arr = check_malloc(sizeof(char **) * (len + 1));

    if (!arr)
        return NULL;
    for (int i = 0; i <= len; i++)
        arr[i] = NULL;
    return arr;
}

int *my_intmalloc(int len)
{
    int *arr = check_malloc((len + 1) * sizeof(int));

    if (!arr)
        return NULL;
    for (int i = 0; i <= len; i++)
        arr[i] = 0;
    return arr;
}
