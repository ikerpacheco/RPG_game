/*
** EPITECH PROJECT, 2022
** inventory update
** File description:
** inventory
*/

#include "my_rpg.h"
#include <SFML/Graphics.h>

void update_inventory(inventory_t *inventory, view_t *view, sfVector2i mouse)
{
    if (!inventory)
        return;
    if (inventory->pos)
        update_pos_view(view, inventory->pos, inventory->offset);
    if (inventory->pos && inventory->render)
        apply_pos(inventory->pos, inventory->render);
    for (int i = 0; inventory->slots[i]; i++)
        update_slot(inventory->slots[i], view, mouse);
}