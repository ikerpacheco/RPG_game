/*
** EPITECH PROJECT, 2022
** init_tiles
** File description:
** get the tiles of scenes
*/

#include "libmy.h"
#include "my_rpg.h"

int **init_tiles(char *path)
{
    FILE *fp = fopen(path, "r");
    int width = 80;
    int height = 45;
    int **intarr = my_intarrmalloc(width, height);
    char **arr = NULL;
    int i = 0;

    for (char *line = NULL; (line = read_line(fp)); i++) {
        arr = my_stoa(line, ',');
        if (i == height)
            return intarr;
        for (int j = 0; j < width; j++)
            intarr[i][j] = (my_atoi(arr[j]) ? 1 : 0);
    }
    return intarr;
}
