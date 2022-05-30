/*
** EPITECH PROJECT, 2022
** ignore control c
** File description:
** SE
*/

#include <signal.h>
#include <unistd.h>
#include "libmy.h"

void interrupt_handler(int signal)
{
    (void)signal;
    write(1, "\n", 1);
}

bool init_minishell(void)
{
    extern char **__environ;

    signal(SIGINT, &interrupt_handler);
    signal(SIGTSTP, &interrupt_handler);
    __environ = my_arrdup(__environ);
    if (!__environ)
        return false;
    return true;
}
