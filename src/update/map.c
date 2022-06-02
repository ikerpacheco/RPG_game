/*
** EPITECH PROJECT, 2022
** map
** File description:
** update map
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "structs.h"

void update_spawns(spawn_t *spawn, entity_t *player, map_t *map, float delta)
{
    int i = 0;

    spawn->elapsed += delta;
    if (spawn->elapsed < spawn->time)
        return;
    for (; i < map->max_enemies && map->enemies[i]; i++);
    if (i == map->max_enemies)
        return;
    map->enemies[i] = init_entity(spawn->arr);
    scale_entity(map->enemies[i], spawn->scale, spawn->scalar);
    update_enemy_move(map->enemies[i], player);
    spawn->elapsed = 0;
}

void update_door(game_t *game, door_t *door, pos_t *pos, float delta)
{
    (void)delta;
    if (!door || !game)
        return;
    if (!sfFloatRect_contains(&door->rect->rect, pos->pos.x, pos->pos.y))
        return;
    game->player->image->pos->pos = door->pos->pos;
    game->player->image->pos->applied = sfFalse;
    game->i_map = door->scene;
}

void update_map(game_t *game, view_t *view, float delta)
{
    map_t *map = NULL;
    pos_t *pos = NULL;

    if (!(map = game->maps[game->i_map]))
        return;
    if (map->bg)
        update_image(map->bg, delta);
    if (!(pos = game->player->image->pos))
        return;
    for (int i = 0; map->objects && map->objects[i]; i++) {
        update_object(map->objects[i], view, delta);
        check_quest(map->objects[i], game->quests, game->player->pos);
    }
    for (int i = 0; map->spawns && map->spawns[i]; i++)
        update_spawns(map->spawns[i], game->player, map, delta);
    for (int i = 0; map->doors && map->doors[i]; i++)
        update_door(game, map->doors[i], pos, delta);
    for (int i = 0; map->enemies && map->enemies[i] && map->layer; i++)
        update_enemy(map->enemies[i], game->player, map->layer, delta);
    if (map->music)
        update_music(map->music, game->i_map);
}
