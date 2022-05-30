/*
** EPITECH PROJECT, 2022
** minishell 1
** File description:
** built-in commands
*/

#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"
#include "minishell.h"

bool print_env(void)
{
    char **env = __environ;

    for (int i = 0; env[i]; i++)
        my_printf("%s\n", env[i]);
    return true;
}

void unset_env_var(char *key)
{
    char *env_var = get_env_key(key);
    int i = -1;

    if (!env_var)
        return;
    if (!__environ)
        return;
    while (__environ[++i] != env_var);
    for (; __environ[i + 1]; i++)
        __environ[i] = __environ[i + 1];
    __environ[i] = NULL;
}

bool unset_env(char **command, int len)
{
    if (len == 1) {
        my_perror("unsetenv: Too few arguments.\n");
        return false;
    }
    for (int i = 1; command[i]; i++)
        unset_env_var(command[i]);
    return true;
}

char *check_setenv(char **command, int len)
{
    if (len == 0)
        print_env();
    if (len > 2)
        my_perror("setenv: Too many arguments.\n");
    if (len == 0 || len > 2)
        return NULL;
    if (!(my_str_isalphanum(command[0]))) {
        my_perror("setenv: ");
        my_perror("Variable name must contain alphanumeric characters.\n");
        return NULL;
    }
    return command[0];
}

bool set_env(char **command, int len)
{
    char *key = check_setenv(++command, --len);
    char *value = NULL;
    char *env_var = NULL;
    int i = -1;
    int n = my_strlen(key);

    if (!key)
        return false;
    value = (len == 2 ? command[1] : "");
    if (!(env_var = get_env_key(key))) {
        __environ = my_arrdup(__environ);
        while (__environ[++i]);
        __environ[i] = my_strcat(my_strcat(key, "="), value);
        return true;
    }
    for (i = 0; __environ[i] && my_strncmp(__environ[i], key, n); i++);
    __environ[i] = my_strcat(my_strcat(key, "="), value);
    return true;
}
