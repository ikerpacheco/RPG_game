/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stdlib.h>
#include "libmy.h"
#include "my_rpg.h"

rpg_t *init_rpg(void)
{
    FILE *stream = fopen(".config/rpg", "r");
    rpg_t *rpg = check_malloc(sizeof(rpg_t));
    char **arr = NULL;

    if (!rpg || !stream)
        return NULL;
    *rpg = (rpg_t){0, 0, NULL, NULL, NULL, 0};
    for (char *line = NULL; (line = read_line(stream));) {
        arr = my_stoa(line, ':');
        if (my_arrlen(arr) == 4 || !my_strcmp(arr[0], "window"))
            rpg->window = init_window(arr + 1);
        if (rpg->window && my_arrlen(arr) == 2 && !my_strcmp(arr[0], "scenes"))
            rpg->scenes = init_scenes(arr[1]);
    }
    if (!rpg->scenes || !rpg->window)
        return NULL;
    rpg->clock = sfClock_create();
    rpg->lang = 0;
    fclose(stream);
    return rpg;
}
