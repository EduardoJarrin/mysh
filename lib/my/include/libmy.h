/*
** EPITECH PROJECT, 2021
** includes
** File description:
** SE
*/

#ifndef LIBMY_H_
    #define LIBMY_H_

    #include <stdio.h>
    #include <stdbool.h>

    #define char_is_lower(c) (c >= 'a' && c <= 'z')
    #define char_is_upper(c) (c >= 'A' && c <= 'Z')
    #define char_is_num(c) (c >= '0' && c <= '9')
    #define char_is_alpha(c) (char_is_lower(c) || char_is_upper(c))
    #define char_is_alphanum(c) (char_is_alpha(c) || char_is_num(c))

    bool is_dir(char const *path);
    void *check_malloc(size_t size);
    int count_chars(char *str, char letter);
    char *dec_to_bin(unsigned int dec);
    char *dec_to_oct(unsigned int dec);
    void free_arr(char **arr);
    char **my_arrdup(char **arr);
    int my_arrlen(char **arr);
    char **my_arrmalloc(int len);
    char *my_cleanstr(char *str);
    unsigned int my_intlen(int);
    void my_printf(char *, ...);
    void my_putaddress(unsigned long);
    void my_putchar(char);
    void my_perror(char const *str);
    void my_putnbr(int nb);
    void my_putnbr_base(int nb, char *base);
    void my_putstr(char const *str);
    char *my_strcat(char *dest, char const *src);
    char *my_strmalloc(int len);
    bool my_str_isalphanum(char const *str);
    char **my_stoa(char *str, char sep);
    char *my_strdupcat(char *dest, char const *src);
    int my_strcmp(char const *str1, char const *str2);
    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    int my_strncmp(char const *s1, char const *s2, int n);
    int my_strlen(char const *str);
    void my_strreplace(char *str, char replaced, char replacer);
    char *my_strstr(char *str, char const *to_find);
    char *my_strstrip(char *str);
    int powerof(int base, int exponent);
    char *read_line(FILE *stream);
    char *remove_extra_sep(char *str);

#endif
