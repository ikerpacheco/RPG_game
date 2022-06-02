/*
** EPITECH PROJECT, 2022
** add_item
** File description:
** add_item
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "libmy.h"
#include "my_rpg.h"

render_t *copy_render(render_t *render)
{
    render_t *new_render = NULL;

    if (!(new_render = check_malloc(sizeof(render_t))))
        return NULL;
    new_render->sprite = sfSprite_copy(render->sprite);
    new_render->render = render->render;
    return new_render;
}

item_t *duplicate_struct(item_t *item)
{
    item_t *new_item = NULL;

    if (!(new_item = check_malloc(sizeof(item_t))))
        return NULL;
    new_item->name = item->name;
    new_item->id = item->id;
    new_item->render = copy_render(item->render);
    new_item->hp = item->hp;
    new_item->range = item->range;
    new_item->damage = item->damage;
    new_item->att_speed = item->att_speed;
    new_item->armor = item->armor;
    new_item->pos = item->pos;
    return new_item;
}
