/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** SE
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy.h"
#include "mysh.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

TestSuite(prompt, .init = redirect_all_std);

Test(prompt, no_environ)
{
    extern char **__environ;

    __environ = NULL;
    display_prompt();
    cr_assert_stdout_eq_str("$ > ");
}

Test(prompt, pwd_user)
{
    extern char **__environ;
    char *user = "eduardo";
    char **arr = my_stoa(my_strdup("setenv USER eduardo"), ' ');
    char *path = "getcwd(NULL, 0)";

    set_env(arr, 3);
    arr[1] = "PWD";
    arr[2] = path;
    set_env(arr, 3);
    free(arr);
    display_prompt();
    cr_assert_stdout_eq_str(my_strcat(my_strcat(path, my_strcat(" | ", user)), " > "));
}

Test(prompt, user)
{
    extern char **__environ;
    char **arr = my_stoa(my_strdup("setenv USER eduardo"), ' ');
    char *user = "eduardo";

    arr[0] = "setenv";
    arr[1] = "USER";
    arr[2] = user;
    arr[3] = NULL;
    set_env(arr, 3);
    arr[1] = "PWD";
    unset_env(arr, 2);
    display_prompt();
    cr_assert_stdout_eq_str(my_strcat(user, " > "));
}

Test(prompt, pwd)
{
    extern char **__environ;
    char **arr = my_stoa(my_strdup("setenv PWD random/pwd"), ' ');
    char *path = "random/pwd";

    arr[0] = "setenv";
    arr[1] = "PWD";
    arr[2] = path;
    arr[3] = NULL;
    set_env(arr, 3);
    arr[1] = "USER";
    unset_env(arr, 2);
    display_prompt();
    cr_assert_stdout_eq_str(my_strcat(path, " > "));
}

Test(prompt, home)
{
    extern char **__environ;
    char *path = get_env_value("HOME");
    char **arr = my_stoa(my_strcat("setenv PWD ", path), ' ');

    set_env(arr, 3);
    arr[1] = "USER";
    unset_env(arr, 2);
    display_prompt();
    cr_assert_stdout_eq_str("~ > ");
}
