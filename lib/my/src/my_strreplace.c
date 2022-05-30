/*
** EPITECH PROJECT, 2022
** my string format
** File description:
** SE
*/

void my_strreplace(char *str, char replaced, char replacer)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == replaced)
            str[i] = replacer;
}
