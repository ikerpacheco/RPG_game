/*
** EPITECH PROJECT, 2022
** move_items
** File description:
** move_items
*/

#include "my_rpg.h"

void set_change(slot_t **slot, int first_slot, int i)
{
    int type = check_item_ype(slot[first_slot]);

    if (slot[i]->item || first_slot == i || !slot[first_slot]->item)
        return;
    if (type == 1 && i != 35 && i > 34)
        return;
    if (type == 2 && i != 36 && i > 34)
        return;
    if (type == 3 && i != 37 && i > 34)
        return;
    if (type == 4 && i != 38 && i > 34)
        return;
    if (type == 5 && i != 39 && i > 34)
        return;
    if (type == 6 && i > 34 && i > 34)
        return;
    slot[i]->item = slot[first_slot]->item;
    slot[i]->item->pos->pos.x = slot[i]->pos->pos.x + 20;
    slot[i]->item->pos->pos.y = slot[i]->pos->pos.y + 20;
    slot[i]->item->pos->applied = sfFalse;
    slot[first_slot]->item = NULL;
}

void check_second_position(inventory_t *inventory, sfRenderWindow *window,
sfEvent evt)
{
    int i = 0;
    sfVector2i mouse = (sfVector2i){0, 0};
    slot_t **slot = inventory->slots;
    int first_slot = inventory->first_slot;

    if (evt.type == sfEvtMouseButtonReleased &&
        evt.mouseButton.button == sfMouseLeft) {
        mouse = sfMouse_getPositionRenderWindow(window);
        for (i = 0; slot[i]; i++)
            if (sfFloatRect_contains(&slot[i]->rect->rect, mouse.x,
                mouse.y))
                break;
        if (i == 40 || slot[i]->item || first_slot == i || !slot[first_slot]->item)
            return;
        set_change(slot, first_slot, i);
    }
}

void check_first_position(inventory_t *inventory, sfRenderWindow *window,
sfEvent evt)
{
    sfVector2i mouse = (sfVector2i){0, 0};
    slot_t **slot = inventory->slots;

    if (evt.type == sfEvtMouseButtonPressed &&
        evt.mouseButton.button == sfMouseLeft) {
        mouse = sfMouse_getPositionRenderWindow(window);
        for (int i = 0; slot[i]; i++)
            if (sfFloatRect_contains(&slot[i]->rect->rect, mouse.x, mouse.y))
                inventory->first_slot = i;
    }
}

void move_items(sfEvent evt, inventory_t *inventory, rpg_t *rpg)
{
    sfVector2i mouse = rpg->window->mouse_pos;
    slot_t *slot = NULL;
    int i = 0;

    if (!inventory || inventory->showed == 0)
        return;
    for (i = 0; inventory->slots[i]; i++) {
        slot = inventory->slots[i];
        if (sfFloatRect_contains(&slot->rect->rect, mouse.x, mouse.y))
            apply_pos(slot->pos, slot->render[1]);
    }
    check_first_position(inventory, rpg->window->window, evt);
    check_second_position(inventory, rpg->window->window, evt);
}