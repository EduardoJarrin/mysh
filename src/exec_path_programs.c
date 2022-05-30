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
    char *attempt = NULL;
    char *program_path = my_strcat("/", program);

    for (int i = 0; paths[i]; i++) {
        attempt = my_strcat(paths[i], program_path);
        if (access(attempt, F_OK) == 0) {
            free(program_path);
            return attempt;
        }
        free(attempt);
    }
    if (access(program, F_OK) == 0)
        return program;
    free(program_path);
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
    char *path = NULL;

    if (!command || len == 0)
        return false;
    if (!(path = get_program_path(command[0]))) {
        my_perror(command[0]);
        my_perror(": Command not found.\n");
        return false;
    }
    if (access(path, X_OK) == -1 || is_dir(path)) {
        my_perror(path);
        my_perror(": Permission denied.\n");
        return false;
    }
    if (!(child_pid = fork()))
        if (execve(path, command, __environ) == -1) {
            fprintf(stderr, "%m\n");
            exit(84);
        }
    if (waitpid(child_pid, &status, WUNTRACED) != (pid_t)0)
        return check_child(status);
    return true;
}
