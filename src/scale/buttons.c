/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics/Sprite.h>
#include "my_rpg.h"

void scale_rect(rect_t *rect, float scalar)
{
    rect->rect.top *= scalar;
    rect->rect.left *= scalar;
    rect->rect.width *= scalar;
    rect->rect.height *= scalar;
}

void scale_grid(grid_t *grid, float scalar)
{
    grid->sep.x *= scalar;
    grid->sep.y *= scalar;
    grid->size.x *= scalar;
    grid->size.y *= scalar;
}

void scale_buttons(button_t **butt, sfVector2u size, float scale, float scalar)
{
    for (int i = 0; butt[i]; i++) {
        if (butt[i]->render && butt[i]->render[0])
            scale_render(butt[i]->render[0], scale);
        if (butt[i]->render && butt[i]->render[1])
            scale_render(butt[i]->render[1], scale);
        if (butt[i]->grid)
            scale_grid(butt[i]->grid, scalar);
        if (butt[i]->grid && butt[i]->pos)
            butt[i]->pos->pos = grid_pos(size, butt[i]->grid);
        if (butt[i]->grid && butt[i]->pos && butt[i]->rect)
            butt[i]->rect = init_rect(butt[i]->pos->pos, butt[i]->grid->size);
    }
}
