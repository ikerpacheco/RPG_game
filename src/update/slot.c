/*
** EPITECH PROJECT, 2022
** slot
** File description:
** slot
*/

#include "my_rpg.h"
#include <SFML/Graphics.h>

void update_slot(slot_t *slot, view_t *view, sfVector2i mouse)
{
    int *i = NULL;

    if (!slot)
        return;
    i = &slot->r_index;
    if (slot->render) {
        *i = (int)sfFloatRect_contains(&slot->rect->rect, mouse.x, mouse.y);
        for (int j = 0; slot->render[j]; j++) {
            slot->render[j]->render = sfFalse;
            update_pos_view(view, slot->pos, slot->offset);
            apply_pos(slot->pos, slot->render[j]);
        }
        slot->render[*i]->render = sfTrue;
    }
    if (slot->item)
        update_item(slot->item);
}