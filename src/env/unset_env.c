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

void unset_env_var(char *key)
{
    char *env_var = get_env_key(key);
    int i = -1;

    if (!env_var)
        return;
    if (!__environ)
        return;
    while (__environ[++i] != env_var);
    free(__environ[i]);
    for (; __environ[i + 1]; i++)
        __environ[i] = __environ[i + 1];
    __environ[i] = NULL;
}

bool unset_env(char **command, int len)
{
    if (!command)
        return false;
    if (len == 1) {
        my_perror("unsetenv: Too few arguments.\n");
        return free_command_return(command, false);
    }
    for (int i = 1; command[i]; i++) {
        if (!my_strcmp(command[i], "*")) {
            free_arr(__environ);
            __environ = my_arrmalloc(0);
            return free_command_return(command, true);
        }
        unset_env_var(command[i]);
    }
    return free_command_return(command, true);
}
