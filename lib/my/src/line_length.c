/*
** EPITECH PROJECT, 2021
** Line length
** File description:
** SE
*/

unsigned int line_length(char const *input)
{
    unsigned int length = 0;

    while (input[length] != '\n' && input[length] != '\0')
        length++;
    return length;
}

unsigned int nl_counter(char const *input)
{
    unsigned int nl = 0;

    for (unsigned int i = 0; input[i]; i++)
        if (input[i] == '\n')
            nl++;
    return nl;
}
