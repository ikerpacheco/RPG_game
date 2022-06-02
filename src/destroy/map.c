/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stdlib.h>
#include <SFML/Graphics/View.h>
#include "structs.h"
#include "my_rpg.h"

void destroy_door(door_t *door)
{
    if (door->pos)
        free(door->pos);
    free(door);
}

void destroy_object(object_t *object)
{
    if (object->chatbox)
        destroy_render(object->chatbox);
    if (object->speaker)
        destroy_render(object->speaker);
    for (int i = 0; object->texts && object->texts[i]; i++)
        destroy_text(object->texts[i]);
    if (object->texts)
        free(object->texts);
    free(object);
}

void destroy_map(map_t *map)
{
    if (map->bg)
        destroy_image(map->bg);
    for (int i = 0; map->doors && map->doors[i]; i++)
        destroy_door(map->doors[i]);
    if (map->doors)
        free(map->doors);
    for (int i = 0; map->layer && map->layer[i]; i++)
        free(map->layer[i]);
    if (map->layer)
        free(map->layer);
    for (int i = 0; map->objects && map->objects[i]; i++)
        destroy_object(map->objects[i]);
    if (map->objects)
        free(map->objects);
    free(map);
}
