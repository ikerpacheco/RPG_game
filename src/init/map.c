/*
** EPITECH PROJECT, 2022
** map
** File description:
** init maps
*/

#include <stdlib.h>
#include "libmy.h"
#include "my_rpg.h"

spawn_t **init_spawns(int nb, FILE *stream)
{
    spawn_t **spawns = check_malloc((nb + 1) * sizeof(spawn_t *));
    char *line = NULL;
    char **arr = NULL;

    if (!spawns)
        return NULL;
    for (int i = 0; i < nb && (line = read_line(stream)); i++) {
        arr = my_stoa(line, ':');
        if (my_arrlen(arr) == 17 && !my_strcmp(arr[0], "spawn")) {
            spawns[i] = check_malloc(sizeof(spawn_t));
            if (!spawns[i])
                return NULL;
            *spawns[i] = (spawn_t){NULL, 0, 0, 0, 0};
            spawns[i]->elapsed = 0;
            spawns[i]->time = my_atof(arr[1]);
            spawns[i]->arr = arr + 2;
        }
    }
    spawns[nb] = NULL;
    return spawns;
}

void fill_map(map_t *map, char **arr, FILE *stream)
{
    if (my_arrlen(arr) == 15 && !my_strcmp(arr[0], "bg"))
        map->bg = init_image(arr + 1);
    if (my_arrlen(arr) == 2 && !my_strcmp(arr[0], "objects"))
        map->objects = init_object_grid(arr + 1, stream);
    if (my_arrlen(arr) == 2 && !my_strcmp(arr[0], "doors"))
        map->doors = init_door_grid(arr + 1, stream);
    if (my_arrlen(arr) == 2 && !my_strcmp(arr[0], "enemies")) {
        map->max_enemies = my_atoi(arr[1]);
        map->enemies = check_malloc(sizeof(entity_t) * (map->max_enemies + 1));
        for (int i = 0; i <= map->max_enemies; i++)
            map->enemies[i] = NULL;
    }
    if (my_arrlen(arr) == 2 && !my_strcmp(arr[0], "spawns"))
        map->spawns = init_spawns(my_atoi(arr[1]), stream);
    if (my_arrlen(arr) == 3 && !my_strcmp(arr[0], "music"))
        map->music = init_music(arr + 1);
}

map_t *map_from_path(int id, char *path, char *layer)
{
    map_t *map = check_malloc(sizeof(map_t));
    FILE *stream = fopen(path, "r");
    char **arr = NULL;

    if (!map)
        return NULL;
    *map = (map_t){NULL, NULL, 0, NULL, NULL, 0, NULL, NULL, NULL};
    map->id = id;
    for (char *line = NULL; (line = read_line(stream)); free(arr)) {
        arr = my_stoa(line, ':');
        fill_map(map, arr, stream);
        map->layer = init_tiles(layer);
    }
    return map;
}

map_t **init_map_grid(char **arr, FILE *stream)
{
    int nb = my_atoi(arr[0]);
    map_t **maps = NULL;

    if (!(maps = check_malloc((nb + 1) * sizeof(map_t *))))
        return NULL;
    for (int i = 0; i < nb; i++) {
        arr = my_stoa(read_line(stream), ':');
        if (my_arrlen(arr) == 4 && !my_strcmp(arr[0], "map"))
            maps[i] = map_from_path(my_atoi(arr[1]), arr[2], arr[3]);
        free(arr);
    }
    maps[nb] = NULL;
    return maps;
}
