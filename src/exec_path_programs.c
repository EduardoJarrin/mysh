/*
** EPITECH PROJECT, 2022
** minishell 1
** File description:
** execute programs
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "libmy.h"
#include "minishell.h"

char *get_program_path(char *program)
{
    char *path = get_env_value("PATH");
    char **paths = my_str_to_word_array(my_strdup(path), ':');
    char *dup = my_strdup(program);
    char *attempt = NULL;

    if (!access(program, X_OK))
        return program;
    program = my_strcat("/", dup);
    free(dup);
    for (int i = 0; paths[i]; i++) {
        attempt = my_strcat(paths[i], program);
        if (!access(attempt, X_OK)) {
            free(program);
            return attempt;
        }
        free(attempt);
    }
    free(program);
    return NULL;
}

bool check_child(int status)
{
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
        return true;
    if (WIFEXITED(status) && WEXITSTATUS(status) == 84)
        return false;
    if (!WIFSIGNALED(status))
        return true;
    if (status == 136)
        my_perror("Floating exception");
    if (status == 139)
        my_perror("Segmentation fault");
    if (WCOREDUMP(status))
        my_perror(" (core dumped)");
    my_perror("\n");
    return false;
}

bool exec_program(char **command, int len)
{
    int child_pid = 0;
    int status = 0;
    char *path = (char *)0;

    if (!command || len == 0)
        return false;
    if (!(path = get_program_path(command[0]))) {
        my_perror(command[0]);
        my_perror(": Command not found.\n");
        return false;
    }
    if (!(child_pid = fork()))
        if (execve((!path ? command[0] : path), command, __environ) == -1) {
            my_perror((!path ? command[0] : path));
            my_perror(": Permission denied.\n");
            exit(84);
        }
    if (waitpid(child_pid, &status, WUNTRACED) != (pid_t)0)
        return check_child(status);
    return true;
}
