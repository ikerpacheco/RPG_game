/*
** EPITECH PROJECT, 2022
** get_file
** File description:
** all the file related functions
*/

#include "libmy.h"

int file_size(char const *file)
{
    int size = 0;
    struct stat buff;

    if (stat(file, &buff) == 0)
        size = buff.st_size;
    if (size == 0)
        return 84;
    return size;
}

int open_file(char const *filepath)
{
    int result = open(filepath, O_RDONLY);

    if (result == -1) {
        return 84;
    }
    return (result);
}

char *get_file(char *filename)
{
    int fd = open_file(filename);
    int size = file_size(filename);
    char *buff = malloc(sizeof(char) * size + 1);

    buff[size] = '\0';
    if (read(fd, buff, size) == -1) {
        return NULL;
    }
    return buff;
}
