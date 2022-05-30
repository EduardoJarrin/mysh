/*
** EPITECH PROJECT, 2021
** MY_COMPUTE_POWER_REC
** File description:
** Raises nb to the power of p rec.
*/

int powerof(int nb, int p)
{
    int result = nb;

    if (p == 0)
        return 1;
    else if (p < 0)
        return 0;
    result = result * powerof(nb, p - 1);
    return result;
}
