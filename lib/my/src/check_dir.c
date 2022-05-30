/*
** EPITECH PROJECT, 2022
** check dir
** File description:
** checks if directory exists
*/

#include <dirent.h>
#include <stdbool.h>
#include <stddef.h>
#include "libmy.h"

bool is_dir(char const *path)
{
    DIR *directory = opendir(path);

    if (!directory)
        return false;
    closedir(directory);
    return true;
}
