/*
** EPITECH PROJECT, 2022
** update items
** File description:
** items
*/

#include "my_rpg.h"
#include <SFML/Graphics.h>

void update_item(item_t *item)
{
    if (!item)
        return;
    if (item->render && item->pos)
        apply_pos(item->pos, item->render);
}