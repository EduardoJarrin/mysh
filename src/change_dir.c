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
    char *str = my_strdup("setenv OLDPWD ");
    char **arr = my_stoa(str, ' ');
    char *pwd = NULL;

    if (!arr)
        return;
    pwd = getcwd(NULL, 0);
    arr[2] = pwd;
    chdir(path);
    set_env(arr, 3);
    free(str);
    free(pwd);
    str = my_strdup("setenv PWD ");
    arr = my_stoa(str, ' ');
    pwd = getcwd(NULL, 0);
    arr[2] = pwd;
    set_env(arr, 3);
    free(str);
    free(pwd);
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
    char *path = (len == 1 ? "~" : command[1]);

    free(command);
    if (len > 2) {
        my_perror("cd: Too many arguments.\n");
        return false;
    }
    path = cd_special_paths(path);
    if ((err += stat(path, &statbuf)) == -1 || !(err += is_dir(path))) {
        my_perror(path);
        my_perror((err == -1) ? CD_NO_FILE_DIR : CD_NOT_DIR);
        return false;
    }
    cd_path(path);
    return true;
}
