/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stdlib.h>
#include "my_rpg.h"

void destroy_rpg(rpg_t *rpg)
{
    if (!rpg)
        return;
    if (rpg->clock)
        sfClock_destroy(rpg->clock);
    if (rpg->window)
        destroy_window(rpg->window);
    if (rpg->scenes)
        destroy_scenes(rpg->scenes);
    if (rpg)
        free(rpg);
}
