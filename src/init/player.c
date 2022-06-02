/*
** EPITECH PROJECT, 2022
** player
** File description:
** init the player in each scene
*/

#include "libmy.h"
#include "my_rpg.h"

entity_t *init_entity(char **arr)
{
    entity_t *entity = check_malloc(sizeof(entity_t));
    sfVector2f size = {0, 0};

    if (!entity)
        return NULL;
    *entity = (entity_t){NULL, NULL, NULL, NULL, NULL, 0};
    entity->direction = 0;
    entity->image = init_image(arr);
    entity->pos = entity->image->pos;
    entity->move = entity->image->move;
    entity->stats = init_stats(arr[14]);
    size = (sfVector2f){my_atof(arr[7]), my_atof(arr[8])};
    entity->rect = init_rect(entity->pos->pos, size);
    return entity;
}
