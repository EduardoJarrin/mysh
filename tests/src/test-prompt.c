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
    init_minishell();
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
    char *user = "eduardo";
    char **arr = my_stoa(my_strdup("setenv USER eduardo"), ' ');
    char *path = "getcwd(NULL, 0)";

    set_env(arr, 3);
    arr = my_stoa(my_strdupcat("setenv PWD ", path), ' ');
    arr[1] = "PWD";
    arr[2] = path;
    set_env(arr, 3);
    display_prompt();
    cr_assert_stdout_eq_str(my_strdupcat(my_strdupcat(path, my_strdupcat(" | ", user)), " > "));
}

Test(prompt, user)
{
    char **arr = my_stoa(my_strdup("setenv USER eduardo"), ' ');
    char *user = "eduardo";

    arr[0] = "setenv";
    arr[1] = "USER";
    arr[2] = user;
    set_env(arr, 3);
    arr = my_stoa(my_strdup("unsetenv PWD"), ' ');
    unset_env(arr, 2);
    display_prompt();
    cr_assert_stdout_eq_str(my_strdupcat(user, " > "));
}

Test(prompt, pwd)
{
    char **arr = my_stoa(my_strdup("setenv PWD random/pwd"), ' ');
    char *path = "random/pwd";

    arr[0] = "setenv";
    arr[1] = "PWD";
    arr[2] = path;
    set_env(arr, 3);
    arr[1] = "USER";
    unset_env(arr, 2);
    display_prompt();
    cr_assert_stdout_eq_str(my_strdupcat(path, " > "));
}

Test(prompt, home)
{
    char *path = get_env_value("HOME");
    char **arr = my_stoa(my_strdupcat("setenv PWD ", path), ' ');

    set_env(arr, 3);
    arr[1] = "USER";
    unset_env(arr, 2);
    display_prompt();
    cr_assert_stdout_eq_str("~ > ");
}
