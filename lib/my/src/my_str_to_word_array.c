/*
** EPITECH PROJECT, 2022
** str_to_word_array
** File description:
** SE
*/

#include <stdlib.h>
#include "libmy.h"

char **my_str_to_word_array(char *str, char sep)
{
    int words = count_chars(str, sep) + 1;
    char **word_array = check_malloc((words + 1) * sizeof(char *));

    for (int i = 0; i < words; i++) {
        word_array[i] = str;
        while (*str != '\0' && *str != sep)
            str++;
        *(str++) = '\0';
    }
    word_array[words] = NULL;
    return word_array;
}
