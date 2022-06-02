/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/View.h>
#include "my_rpg.h"

void scale_object(object_t *object, float scale, float scalar)
{
    if (object->chatbox)
        scale_render(object->chatbox, scale);
    object->offset_c.x *= scalar;
    object->offset_c.y *= scalar;
    object->offset_s.x *= scalar;
    object->offset_s.y *= scalar;
    if (object->pos_c)
        scale_pos(object->pos_c, scalar);
    if (object->pos_s)
        scale_pos(object->pos_s, scalar);
    if (object->speaker)
        scale_render(object->speaker, scale);
    for (int i = 0; object->texts && object->texts[i]; i++)
        scale_text(object->texts[i], scalar);
    if (object->rect)
        scale_rect(object->rect, scalar);
}

void scale_entity(entity_t *entity, float scale, float scalar)
{
    if (entity->image)
        scale_image(entity->image, scale, scalar);
    if (entity->rect)
        scale_rect(entity->rect, scalar);
}

void scale_map(map_t *map, float scale, float scalar)
{
    if (map->bg)
        scale_image(map->bg, scalar, scale);
    for (int i = 0; map->doors && map->doors[i]; i++)
        if (map->doors[i]->pos) {
            scale_pos(map->doors[i]->pos, scale);
            scale_rect(map->doors[i]->rect, scale);
        }
    for (int i = 0; map->objects && map->objects[i]; i++)
        scale_object(map->objects[i], scale, scalar);
    for (int i = 0; map->spawns && map->spawns[i]; i++) {
        map->spawns[i]->scale = scale;
        map->spawns[i]->scalar = scalar;
    }
    for (int i = 0; map->enemies && map->enemies[i]; i++)
        scale_entity(map->enemies[i], scale, scalar);
}
