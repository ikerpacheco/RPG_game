/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics/Sprite.h>
#include "my_rpg.h"

void scale_render(render_t *render, float scale)
{
    if (render->sprite)
        sfSprite_setScale(render->sprite, (sfVector2f){scale, scale});
}

void scale_move(move_t *move, float scalar)
{
    move->move = (sfVector2f){move->move.x * scalar, move->move.y * scalar};
}

void scale_pos(pos_t *pos, float scalar)
{
    pos->pos = (sfVector2f){pos->pos.x * scalar, pos->pos.y * scalar};
    pos->applied = sfFalse;
}

void scale_image(image_t *image, float scale, float scalar)
{
    if (image->move)
        scale_move(image->move, scalar);
    if (image->pos)
        scale_pos(image->pos, scalar);
    if (image->render)
        scale_render(image->render, scale);
}
