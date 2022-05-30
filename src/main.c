/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** main
*/

#include "libmy.h"
#include "minishell.h"

int main(int ac, char **av)
{
    int error = check_args(--ac, ++av);
    extern char **__environ;

    if (error)
        return error;
    if (!init_minishell())
        return 84;
    my_sh();
    free_arr(__environ);
    return 0;
}
