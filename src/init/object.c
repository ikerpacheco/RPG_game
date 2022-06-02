/*
** EPITECH PROJECT, 2022
** object
** File description:
** init object in scene
*/

#include <stdlib.h>
#include "libmy.h"
#include "my_rpg.h"

object_t *init_object(char **arr, FILE *stream)
{
    object_t *object = check_malloc(sizeof(object_t));
    sfVector2f pos = {0, 0};
    sfVector2f size = {0, 0};

    if (!object)
        return NULL;
    *object = (object_t){NULL, NULL, NULL, NULL, {0, 0}, {0, 0}, 0, 0, NULL, 0};
    object->index = -1;
    object->offset_c = (sfVector2f){120, 270};
    object->offset_s = (sfVector2f){145, 230};
    object->pos_c = init_pos(object->offset_c);
    object->pos_s = init_pos(object->offset_s);
    object->speaker = (*(arr[0]) ? init_render(arr[0]) : NULL);
    object->chatbox = (*(arr[1]) ? init_render(arr[1]) : NULL);
    if (*(arr[2]) && *(arr[3]))
        pos = (sfVector2f){my_atof(arr[2]), my_atof(arr[3])};
    if (*(arr[4]) && *(arr[5]))
        size = (sfVector2f){my_atof(arr[4]), my_atof(arr[5])};
    if (*(arr[6]))
        object->quest = my_atoi(arr[6]);
    object->rect = init_rect(pos, size);
    object->texts = init_text_grid(my_stoa(read_line(stream), ':') + 1, stream);
    return object;
}

object_t **init_object_grid(char **arr, FILE *stream)
{
    int nb = my_atoi(arr[0]);
    object_t **objects = NULL;

    if (nb < 0 || !(objects = check_malloc((nb + 1) * sizeof(object_t *))))
        return NULL;
    for (int i = 0; i < nb; i++) {
        arr = my_stoa(read_line(stream), ':');
        if (my_arrlen(arr) == 8 && !my_strcmp(arr[0], "object")) {
            objects[i] = init_object(arr + 1, stream);
        }
        free(arr);
    }
    objects[nb] = NULL;
    return objects;
}
