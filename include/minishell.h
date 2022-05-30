/*
** EPITECH PROJECT, 2021
** functions
** File description:
** functions prototypes
*/

#ifndef MINISHELL_H
    #define MINISHELL_H

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
    exec_bt_t *create_bt(char *input);
    void display_prompt(void);
    bool exec_program(char **command, int len);
    bool exit_sh(char **environ, int exit_status);
    char *get_env_value(char *var);
    char *get_env_key(char *key);
    bool init_minishell(void);
    void my_sh(void);
    bool exec_bt(exec_bt_t *root);
    bool print_env(void);
    bool set_env(char **command, int len);
    bool unset_env(char **command, int len);

#endif
