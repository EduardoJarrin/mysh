/*
** EPITECH PROJECT, 2021
** MY_STRLEN
** File description:
** Return the length of a given string.
*/

int my_strlen(char const *str)
{
    int len = 0;

    if (!str)
        return 0;
    while (str[len])
        len++;
    return (len);
}

int my_intlen(int nb)
{
    int len = (nb ? 0 : 1);

    for (; nb != 0; len++)
        nb /= 10;
    return len;
}

int my_arrlen(char **arr)
{
    int len = 0;

    while (arr[len])
        len++;
    return len;
}
