/*
** EPITECH PROJECT, 2022
** cd
** File description:
** change directory
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "libmy.h"
#include "mysh.h"

void cd_path(char *path)
{
    char **arr = check_malloc(sizeof(char *) * 4);

    if (!arr)
        return;
    arr[0] = "setenv";
    arr[1] = "OLDPWD";
    arr[2] = getcwd(NULL, 0);
    arr[3] = NULL;
    chdir(path);
    set_env(arr, 3);
    arr[1] = "PWD";
    arr[2] = getcwd(NULL, 0);
    set_env(arr, 3);
    free(arr);
}

char *cd_special_paths(char *path)
{
    if (!my_strcmp(path, "~"))
        return get_env_value("HOME");
    if (!my_strcmp(path, "-")) {
        path = get_env_value("OLDPWD");
        my_printf("%s\n", path);
    }
    return path;
}

bool change_dir(char **command, int len)
{
    struct stat statbuf;
    int err = 0;
    char *path = command[1];

    if (len > 2) {
        my_perror("cd: Too many arguments.\n");
        return false;
    }
    path = cd_special_paths(path);
    if ((err += stat(path, &statbuf)) == -1 || !(err += is_dir(path))) {
        my_perror(path);
        if (err == -1)
            my_perror(": No such file or directory.\n");
        else
            my_perror(": Not a directory.\n");
        return false;
    }
    cd_path(path);
    return true;
}
