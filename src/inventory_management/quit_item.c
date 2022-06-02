/*
** EPITECH PROJECT, 2022
** quit_item
** File description:
** quit_item
*/

#include "my_rpg.h"

void quit_items(slot_t **slots)
{
    for (int i = 0; slots[i]; i++) {
        if (!slots[i] || !slots || !slots[i]->item)
            return;
        slots[i]->item = NULL;
        break;
    }
}

void quit_item(sfEvent evt, inventory_t *inventory)
{
    if (evt.key.code == sfKeyQ)
        quit_items(inventory->slots);
}