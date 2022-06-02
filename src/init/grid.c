/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include "libmy.h"
#include "my_rpg.h"

sfVector2f grid_pos(sfVector2u screen, grid_t *grid_s)
{
    sfVector2i grid = grid_s->grid;
    sfVector2i pos = grid_s->pos;
    sfVector2f sep = grid_s->sep;
    sfVector2f size = grid_s->size;
    sfVector2f mid = {screen.x / 2, screen.y / 2};
    sfVector2f total_sep = {sep.x * (grid.x - 1), sep.y * (grid.y - 1)};
    float x0 = mid.x - size.x * grid.x / 2 - total_sep.x / 2;
    float y0 = mid.y - size.y * grid.y / 2 - total_sep.y / 2;
    float x = x0 + size.x * pos.x + sep.x * pos.x;
    float y = y0 + size.y * pos.y + sep.y * pos.y;

    return (sfVector2f){x, y};
}

grid_t *get_grid(sfVector2i grid, sfVector2i pos, sfVector2f si, sfVector2f sep)
{
    grid_t *grid_s = check_malloc(sizeof(grid_t));

    if (!grid_s)
        return NULL;
    *grid_s = (grid_t){grid, pos, si, sep};
    return grid_s;
}
