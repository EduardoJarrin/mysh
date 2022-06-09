/*
** EPITECH PROJECT, 2022
** ignore control c
** File description:
** SE
*/

#include <stdlib.h>
#include "libmy.h"
#include "mysh.h"

void free_bt(exec_bt_t *node)
{
    if (!node)
        return;
    if (node->command)
        free(node->command);
    if (node->sep)
        free(node->sep);
    if (node->right)
        free_bt(node->right);
    if (node->left)
        free_bt(node->left);
    if (node)
        free(node);
}

exec_bt_t *init_node(void)
{
    exec_bt_t *node = check_malloc(sizeof(exec_bt_t));

    if (!node)
        return NULL;
    node->command = NULL;
    node->sep = NULL;
    node->left = NULL;
    node->right = NULL;
    return node;
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
