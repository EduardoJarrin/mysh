/*
** EPITECH PROJECT, 2022
** ignore control c
** File description:
** SE
*/

#include <stdlib.h>
#include "libmy.h"
#include "mysh.h"

void create_branches(exec_bt_t *node);

void divide_branch(exec_bt_t *node, char *sep)
{
    node->left = check_malloc(sizeof(exec_bt_t));
    node->right = check_malloc(sizeof(exec_bt_t));
    node->left->command = node->command;
    node->sep = my_strmalloc(2);
    node->sep[0] = *sep;
    node->right->command = my_cleanstr(sep + 1);
    if (sep[1] == *sep &&
    (*sep == '>' || *sep == '<' || *sep == '|' || *sep == '&')) {
        node->sep[1] = node->sep[0];
        node->right->command = my_cleanstr(node->right->command + 1);
    }
    *sep = '\0';
    node->command = NULL;
    node->left->command = my_cleanstr(node->left->command);
    create_branches(node->left);
    create_branches(node->right);
}

void create_branches(exec_bt_t *node)
{
    char *sep = NULL;

    if ((sep = my_strstr(node->command, ";")))
        return divide_branch(node, sep);
    for (int i = 0; node->command[i]; i++)
        if ((node->command[i] == '&' || node->command[i] == '|')
        && node->command[i] == node->command[i + 1])
            return divide_branch(node, &node->command[i]);
    for (int i = 0; node->command[i]; i++)
        if (node->command[i] == '<' || node->command[i] == '>')
            return divide_branch(node, &node->command[i]);
    if ((sep = my_strstr(node->command, "|")))
        return divide_branch(node, sep);
}

exec_bt_t *create_bt(char *input)
{
    exec_bt_t *root = check_malloc(sizeof(exec_bt_t));

    if (!root)
        return NULL;
    root->sep = NULL;
    root->command = my_cleanstr(input);
    create_branches(root);
    return root;
}
