/*
** EPITECH PROJECT, 2022
** check_malloc3D
** File description:
** malloc a 3D int array
*/

#include "libmy.h"

int *my_intmalloc(int len)
{
    int *arr = check_malloc((len + 1) * sizeof(int));

    if (!arr)
        return NULL;
    for (int i = 0; i <= len; i++)
        arr[i] = 0;
    return arr;
}

int **my_intarrmalloc(int x, int y)
{
    int **arr = check_malloc((y + 1) * sizeof(int *));

    if (!arr)
        return NULL;
    for (int i = 0; i < y; i++)
        arr[i] = (x ? my_intmalloc(x) : NULL);
    arr[y] = NULL;
    return arr;
}

int ***my_3int_arrmalloc(int x, int y, int z)
{
    int ***arr = check_malloc(sizeof(int **) * (z + 1));

    if (!arr)
        return NULL;
    for (int i = 0; i < z; i++)
        arr[i] = (y ? my_intarrmalloc(x, y) : NULL);
    arr[z] = NULL;
    return arr;
}
