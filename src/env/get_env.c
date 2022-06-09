/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** minishell function
*/

#include <stdio.h>
#include <stdlib.h>
#include "libmy.h"

char *get_env_key(char *key)
{
    extern char **__environ;
    int len = my_strlen(key) + 1;

    if (!__environ)
        return NULL;
    key = my_strdupcat(key, "=");
    if (!key)
        return NULL;
    for (int i = 0; __environ[i]; i++)
        if (!my_strncmp(key, __environ[i], len)) {
            free(key);
            return __environ[i];
        }
    free(key);
    return NULL;
}

char *get_env_value(char *var)
{
    extern char **__environ;
    int len = my_strlen(var) + 1;

    if (!__environ)
        return NULL;
    var = my_strdupcat(var, "=");
    for (int i = 0; __environ[i]; i++)
        if (!my_strncmp(__environ[i], var, len)) {
            free(var);
            return __environ[i] + len;
        }
    free(var);
    return NULL;
}
