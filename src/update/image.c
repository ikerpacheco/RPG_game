/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics/Sprite.h>
#include "libmy.h"
#include "my_rpg.h"

void update_pos_view(view_t *view, pos_t *pos, sfVector2f offset)
{
    pos->pos.x = offset.x + view->pos.x;
    pos->pos.y = offset.y + view->pos.y;
    pos->applied = sfFalse;
}

void update_pos(move_t *move, pos_t *pos, float delta)
{
    move->elapsed += delta;
    if (move->elapsed < move->time)
        return;
    pos->pos.x += move->move.x;
    pos->pos.y += move->move.y;
    pos->applied = sfFalse;
    move->elapsed = 0;
}

void apply_pos(pos_t *pos, render_t *render)
{
    if (pos->applied)
        return;
    sfSprite_setPosition(render->sprite, pos->pos);
    pos->applied = sfTrue;
}

void update_image(image_t *image, float delta)
{
    if (!image)
        return;
    if (image->move && image->pos)
        update_pos(image->move, image->pos, delta);
    if (image->pos && image->render)
        apply_pos(image->pos, image->render);
    if (image->ani)
        update_ani(image->ani, delta);
    if (image->render && image->ani)
        apply_ani(image->render, image->ani);
}
