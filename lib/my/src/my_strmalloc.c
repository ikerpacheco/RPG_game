/*
** EPITECH PROJECT, 2021
** Clean check_malloc
** File description:
** Clean check_malloc
*/

#include <stdlib.h>
#include "libmy.h"

void *check_malloc(size_t size)
{
    void *ptr = NULL;

    if (size < 0) {
        my_puterror("Invalid malloc size\n");
        return NULL;
    }
    if (!(ptr = malloc(size)))
        my_puterror("Could not allocate memory correctly\n");
    return ptr;
}

char *my_strmalloc(int len)
{
    char *str = check_malloc(len + 1);

    if (!str)
        return NULL;
    for (int i = 0; i <= len; i++)
        str[i] = '\0';
    return str;
}

char **my_arrmalloc(int x, int y)
{
    char **arr = check_malloc(sizeof(char **) * (y + 1));

    if (!arr)
        return NULL;
    for (int i = 0; i < y; i++)
        arr[i] = (x ? my_strmalloc(x) : NULL);
    arr[y] = NULL;
    return arr;
}
