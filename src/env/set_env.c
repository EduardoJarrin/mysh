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

char *check_setenv(char **command, int len)
{
    if (len > 3)
        my_perror("setenv: Too many arguments.\n");
    if (len == 1 || len > 3)
        return NULL;
    if (!(my_str_isalphanum(command[1])) || !char_is_alpha(command[1][0])) {
        my_perror("setenv: ");
        my_perror(char_is_alpha(command[1][0]) ? ENV_ALPHANUM : ENV_FIRSTCHAR);
        return NULL;
    }
    return command[1];
}

bool set_env(char **command, int len)
{
    char *key = check_setenv(command, len);
    char *value = NULL;
    char *env_var = NULL;
    int i = 0;
    int n = my_strlen(key);

    if (len == 1)
        return print_env();
    if (!key)
        return false;
    value = (len == 3 ? command[2] : "\0");
    if (!(env_var = get_env_key(key)))
        dup_env();
    for (i = 0; __environ[i] && my_strncmp(__environ[i], key, n); i++);
    free(__environ[i]);
    __environ[i] = my_strmalloc(my_strlen(key) + my_strlen(value) + 1);
    my_strcat(my_strcat(my_strcat(__environ[i], key), "="), value);
    return free_command_return(command, true);
}
