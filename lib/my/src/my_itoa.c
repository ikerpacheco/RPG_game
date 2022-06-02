/*
** EPITECH PROJECT, 2022
** my itoa
** File description:
** my_itoa
*/

#include <stdlib.h>

char *my_itoa(int n, char *s)
{
    char *dest = s;
    dest = malloc(sizeof(char) * 20);

    if(n / 10 != 0)
        dest = my_itoa(n/10, dest);
    else if(n < 0)
        *dest++ = '-';

    *dest++ = n % 10 + '0';
    *dest = '\0';

    return dest;
}