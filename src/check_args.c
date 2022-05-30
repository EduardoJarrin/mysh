/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** check arguments
*/

#include "libmy.h"

int usage(void)
{
    my_putstr("USAGE\n\t./mysh [FLAG]\n");
    my_putstr("\nDESCRIPTION\n");
    my_putstr("\n\tSimple UNIX command interpreter.\n");
    my_putstr("\nFLAGS\n");
    my_putstr("\t-h\tdisplays this message and exits.\n");
    return 1;
}

int check_args(int ac, char **av)
{
    if (ac == 1 && my_strcmp(av[0], "-h") == 0)
        return usage();
    if (ac != 0) {
        my_perror("Invalid number of arguments\n");
        return 84;
    }
    return 0;
}
