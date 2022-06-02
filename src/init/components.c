/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "libmy.h"
#include "my_rpg.h"

pos_t *init_pos(sfVector2f pos_v)
{
    pos_t *pos = (pos_t *)check_malloc(sizeof(pos_t));

    if (!pos)
        return NULL;
    pos->applied = false;
    pos->pos = pos_v;
    return pos;
}

move_t *init_move(sfVector2f move_v, float time)
{
    move_t *move = (move_t *)check_malloc(sizeof(move_t));

    if (!move)
        return NULL;
    move->move = move_v;
    move->elapsed = 0;
    move->time = time;
    return move;
}

render_t *init_render(char *path)
{
    render_t *render = (render_t *)check_malloc(sizeof(render_t));
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    if (!render || !texture)
        return NULL;
    render->texture = texture;
    render->render = sfTrue;
    render->sprite = sfSprite_create();
    sfSprite_setTexture(render->sprite, texture, sfFalse);
    return render;
}

ani_t *init_ani(sfIntRect rect, sfVector2i offset, sfVector2i max, float time)
{
    ani_t *ani = (ani_t *)check_malloc(sizeof(ani_t));

    if (!ani)
        return NULL;
    ani->applied = false;
    ani->elapsed = 0;
    ani->max = max;
    ani->offset = offset;
    ani->rect = rect;
    ani->time = time;
    return ani;
}
