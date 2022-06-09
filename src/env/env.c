/*
** EPITECH PROJECT, 2022
** minishell 1
** File description:
** built-in commands
*/

#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"
#include "mysh.h"

bool print_env(void)
{
    char **env = __environ;

    for (int i = 0; env[i]; i++)
        my_printf("%s\n", env[i]);
    return true;
}

void dup_env(void)
{
    extern char **__environ;
    char **tmp = __environ;

    __environ = my_arrmalloc(my_arrlen(__environ) + 1);
    for (int i = 0; tmp[i]; i++)
        __environ[i] = tmp[i];
    free(tmp);
}
