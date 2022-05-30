/*
** EPITECH PROJECT, 2022
** ignore control c
** File description:
** SE
*/

#include <stdlib.h>
#include "libmy.h"
#include "minishell.h"

bool check_sep(exec_bt_t *left, exec_bt_t *right)
{
    if (!*(left->command) || !*(right->command)) {
        my_perror("Invalid null command.\n");
        return false;
    }
    return true;
}

bool exec_sep(exec_bt_t *left, exec_bt_t *right, char *sep)
{
    if (!my_strcmp(sep, ";")) {
        if (!exec_bt(left))
            return false;
        if (!exec_bt(right))
            return false;
    }
    if (!check_sep(left, right))
        return false;
    if (!my_strcmp(sep, "&&"))
        return exec_bt(left) && exec_bt(right);
    if (!my_strcmp(sep, "||"))
        return exec_bt(left) || exec_bt(right);
    return false;
}

bool exec_bt(exec_bt_t *node)
{
    if (!node)
        return true;
    if (node->sep)
        return exec_sep(node->left, node->right, node->sep);
    if (!node->command)
        return false;
    if (!*(node->command))
        return false;
    return builtin_classify(node->command);
}
