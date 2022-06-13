/*
** EPITECH PROJECT, 2021
** Tests
** File description:
** SE
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_std(void);
char *get_input(char *input);

TestSuite(input, .init = redirect_all_std);

Test(input, tabs)
{
    FILE *in = cr_get_redirected_stdin();
    char *input = NULL;

    fprintf(in, "Hello\tthere\t!");
    fclose(in);
    input = get_input(NULL);
    cr_assert_str_eq(input, "Hello there !");
}

Test(input, eof)
{
    FILE *in = cr_get_redirected_stdin();
    char *input = NULL;

    fclose(in);
    input = get_input(NULL);
    cr_assert_null(input);
    cr_assert_stdout_eq_str("exit\n");
}
