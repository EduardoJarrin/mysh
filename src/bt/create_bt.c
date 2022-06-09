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
    node->left = init_node();
    node->right = init_node();
    node->sep = my_strmalloc(2);
    node->sep[0] = sep[0];
    node->right->command = my_cleanstr(sep + 1);
    if (sep[1] == sep[0] &&
    (sep[0] == '>' || sep[0] == '<' || sep[0] == '|' || sep[0] == '&')) {
        node->sep[1] = node->sep[0];
        node->right->command = my_cleanstr(node->right->command + 1);
    }
    sep[0] = '\0';
    node->left->command = my_cleanstr(node->command);
    free(node->command);
    node->command = NULL;
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

void exec_input(char *input)
{
    exec_bt_t *root = init_node();

    if (!root)
        return;
    root->command = my_cleanstr(input);
    create_branches(root);
    exec_bt(root);
    free_bt(root);
}
