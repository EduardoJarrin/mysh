/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** SE
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include "libmy.h"
#include "mysh.h"

void redirect_all_std(void);
char *get_input(char *input);

TestSuite(cd, .init = redirect_all_std);

Test(cd, back)
{
    char **arr = my_stoa(my_strdup("cd ~"), ' ');
    char *path = NULL;

    path = getcwd(path, 0);
    change_dir(arr, 1);
    arr = my_stoa(my_strdup("cd -"), ' ');
    change_dir(arr, 2);
    cr_assert_stdout_eq_str(my_strdupcat(path, "\n"));
}

Test(cd, home)
{
    char **arr = my_stoa(my_strdup("cd ~"), ' ');
    char *path = NULL;

    change_dir(arr, 2);
    cr_assert_str_eq(get_env_value("HOME"), getcwd(path, 0));
}

Test(cd, empty)
{
    char **arr = my_stoa(my_strdup("cd"), ' ');
    char *path = NULL;

    change_dir(arr, 1);
    cr_assert_str_eq(get_env_value("HOME"), getcwd(path, 0));
}

Test(cd, pwd_oldpwd)
{
    char **arr = my_stoa(my_strdup("cd src"), ' ');
    char *oldpwd = NULL;
    char *pwd = NULL;

    oldpwd = getcwd(oldpwd, 0);
    change_dir(arr, 2);
    pwd = getcwd(pwd, 0);
    cr_assert_str_eq(oldpwd, get_env_value("OLDPWD"));
    cr_assert_str_eq(pwd, get_env_value("PWD"));
}

Test(cd, no_file_dir)
{
    char **arr = my_stoa(my_strdup("cd yffhujyf"), ' ');

    change_dir(arr, 2);
    cr_assert_stderr_eq_str("yffhujyf: No such file or directory.\n");
}

Test(cd, not_a_dir)
{
    char **arr = my_stoa(my_strdup("cd Makefile"), ' ');

    change_dir(arr, 2);
    cr_assert_stderr_eq_str("Makefile: Not a directory.\n");
}
