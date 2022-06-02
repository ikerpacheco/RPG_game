/*
** EPITECH PROJECT, 2021
** my_read
** File description:
** reads and checks files
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libmy.h"

char *read_line(FILE *stream)
{
    size_t size = (size_t)0;
    char *ptr = (char *)0;

    if (getline(&ptr, &size, stream) == -1)
        return NULL;
    my_strreplace(ptr, '\n', '\0');
    return ptr;
}
