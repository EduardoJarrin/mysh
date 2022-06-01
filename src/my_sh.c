/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** minishell function
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "libmy.h"
#include "mysh.h"

builtins_t builtins[5] = {
    {"cd", &change_dir},
    {"setenv", &set_env},
    {"unsetenv", &unset_env},
    {"exit", &exit_sh},
    {NULL, NULL}
};

bool exit_sh(char **environ, int exit_status)
{
    my_putstr("exit\n");
    free_arr(environ);
    exit(exit_status);
}

bool builtin_classify(char *input)
{
    char **command = NULL;
    int len = 0;

    if (!my_strcmp(input, "env"))
        return print_env();
    if (!my_strcmp(input, "cd"))
        input = my_strdup("cd ~");
    command = my_stoa(input, ' ');
    if (!command)
        return false;
    len = my_arrlen(command);
    if (len <= 0)
        return false;
    for (int i = 0; builtins[i].command; i++)
        if (!my_strcmp(command[0], builtins[i].command))
            return builtins[i].fn(command, len);
    return exec_program(command, len);
}

char *get_input(char *input)
{
    free(input);
    if (!(input = read_line(stdin))) {
        my_putstr("exit\n");
        return NULL;
    }
    my_strreplace(input, '\t', ' ');
    return input;
}

void display_prompt(void)
{
    char *user = get_env_value("USER");
    char *path = get_env_value("PWD");
    char *home = get_env_value("HOME");
    int home_length = my_strlen(home);

    if (home && path && !my_strncmp(home, path, home_length)) {
        my_putstr("~");
        my_putstr(path + home_length);
    } else {
        my_putstr(path);
    }
    my_putstr((path && user ? " | " : NULL));
    my_putstr(user);
    my_putstr((!path && !user ? "$" : NULL));
    my_putstr(" > ");
}

void print_tree(exec_bt_t *root)
{
    if (!root)
        return;
    if (root->sep)
        my_printf("Operator: %s\n", root->sep);
    if (root->command)
        my_printf("Command: %s\n", root->command);
    if (root->left) {
        my_printf("Left:\n");
        print_tree(root->left);
    }
    if (root->right) {
        my_printf("Right:\n");
        print_tree(root->right);
    }
}

void my_sh(void)
{
    exec_bt_t *root = NULL;

    for (char *input = NULL; true;) {
        display_prompt();
        if (!(input = get_input(input)))
            break;
        if (*input == '\0')
            continue;
        root = create_bt(input);
        exec_bt(root);
    }
}
