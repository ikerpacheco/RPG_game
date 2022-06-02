/*
** EPITECH PROJECT, 2022
** door
** File description:
** init door
*/

#include <stdlib.h>
#include "my_rpg.h"
#include "libmy.h"

door_t *init_door(char **arr)
{
    door_t *door = check_malloc(sizeof(door_t));
    sfVector2f pos = {0, 0};
    sfVector2f size = {0, 0};

    if (!door)
        return NULL;
    *door = (door_t){0, NULL, NULL};
    if (*(arr[0]) && *(arr[1]) && *(arr[2]) && *(arr[3])) {
        pos = (sfVector2f){my_atoi(arr[0]), my_atoi(arr[1])};
        size = (sfVector2f){my_atoi(arr[2]), my_atoi(arr[3])};
        door->rect = init_rect(pos, size);
    }
    if (*(arr[4]))
        door->scene = my_atoi(arr[4]);
    if (*(arr[5]) && *(arr[6]))
        door->pos = init_pos((sfVector2f){my_atoi(arr[5]), my_atoi(arr[6])});
    return door;
}

door_t **init_door_grid(char **arr, FILE *stream)
{
    int nb = my_atoi(arr[0]);
    door_t **doors = NULL;

    if (!(doors = check_malloc((nb + 1) * sizeof(door_t *))))
        return NULL;
    for (int i = 0; i < nb; i++) {
        arr = my_stoa(read_line(stream), ':');
        if (my_arrlen(arr) == 8 && !my_strcmp(arr[0], "door"))
            doors[i] = init_door(arr + 1);
        free(arr);
    }
    doors[nb] = NULL;
    return doors;
}
