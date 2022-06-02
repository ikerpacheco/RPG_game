/*
** EPITECH PROJECT, 2022
** items
** File description:
** items
*/

#include <SFML/Graphics.h>
#include "libmy.h"
#include "my_rpg.h"

item_t *create_item(char **arr)
{
    item_t *item = NULL;

    if (!(item = check_malloc(sizeof(item_t))))
        return NULL;
    *item = (item_t){NULL, 0, NULL, 0, 0, 0, 0, 0, NULL};
    item->name = arr[0];
    item->id = my_atoi(arr[1]);
    item->render = init_render(arr[2]);
    item->hp = my_atoi(arr[3]);
    item->range = my_atoi(arr[4]);
    item->damage = my_atoi(arr[5]);
    item->att_speed = my_atoi(arr[6]);
    item->armor = my_atoi(arr[7]);
    sfSprite_setPosition(item->render->sprite, (sfVector2f){72, 350});
    return item;
}

item_t **init_items(char **arr, FILE *stream)
{
    item_t **items = NULL;
    int nb = my_atoi(arr[0]);

    if (!(items = check_malloc((nb + 1) * sizeof(item_t *))))
        return NULL;
    for (int i = 0; i < nb; i++) {
        arr = my_stoa(read_line(stream), ':');
        if (my_arrlen(arr) == 8)
            items[i] = create_item(arr);
        free(arr);
    }
    items[nb] = NULL;
    return items;
}
