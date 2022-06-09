/*
** EPITECH PROJECT, 2021
** functions
** File description:
** functions prototypes
*/

#ifndef MINISHELL_H
    #define MINISHELL_H

    #include <stdbool.h>

    #define REDIRECT_ERROR "Missing redirect name.\n"
    #define NULL_COMMAND "Invalid null command.\n"
    #define CD_NO_FILE_DIR ": No such file or directory.\n"
    #define CD_NOT_DIR ": Not a directory.\n"
    #define ENV_ALPHANUM "Variable name must contain alphanumeric characters.\n"
    #define ENV_FIRSTCHAR "Variable name must begin with a letter.\n"

    typedef struct exec_bt_s {
        char *sep;
        char *command;
        struct exec_bt_s *left;
        struct exec_bt_s *right;
    } exec_bt_t;

    typedef struct builtins_s {
        char *command;
        bool (*fn)(char **command, int len);
    } builtins_t;

    int check_args(int, char **);
    bool builtin_classify(char *input);
    bool change_dir(char **command, int len);
    void display_prompt(void);
    void dup_env(void);
    void exec_input(char *input);
    bool exec_program(char **command, int len);
    bool exit_sh(char **arr, int exit_status);
    void free_bt(exec_bt_t *node);
    bool free_command_return(char **command, bool return_value);
    char *get_env_value(char *var);
    char *get_env_key(char *key);
    bool init_minishell(void);
    exec_bt_t *init_node(void);
    void my_sh(void);
    bool exec_bt(exec_bt_t *root);
    bool print_env(void);
    void print_tree(exec_bt_t *root);
    bool set_env(char **command, int len);
    bool unset_env(char **command, int len);

#endif
