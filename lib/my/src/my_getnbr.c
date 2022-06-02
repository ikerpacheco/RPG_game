/*
** EPITECH PROJECT, 2021
** my get nbr
** File description:
** Gets number from string
*/

#include "libmy.h"

int my_atoi(char const *str)
{
    int nb = 0;
    int sign = 1;
    int i = 0;

    for (i = 0; str[i] == '+' || str[i] == '-'; i++)
        if (str[i] == '-')
            sign *= -1;
    for (; str[i] && char_is_num(str[i]); i++)
        nb = nb * 10 + (str[i] - '0');
    return nb * sign;
}

float my_atof(char const *str)
{
    float nb = 0;
    float dec = 0;
    int sign = 1;
    int i = 0;
    int div = 10;

    for (i = 0; str[i] == '+' || str[i] == '-'; i++)
        if (str[i] == '-')
            sign *= -1;
    for (; str[i] && str[i] != '.' && char_is_num(str[i]); i++)
        nb = nb * 10 + (str[i] - '0');
    if (str[i] != '.')
        return nb * sign;
    i++;
    for (; str[i] && char_is_num(str[i]); i++) {
        dec += (float)(str[i] - '0') / div;
        div *= 10;
    }
    return (nb + dec) * sign;
}
