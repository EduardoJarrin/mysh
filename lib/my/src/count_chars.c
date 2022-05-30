/*
** EPITECH PROJECT, 2022
** count_chars
** File description:
** count char ocurrences in string
*/

int count_chars(char *str, char letter)
{
    int count = 0;

    while (*str) {
        if (*str == letter)
            count++;
        str++;
    }
    return count;
}
