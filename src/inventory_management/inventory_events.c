/*
** EPITECH PROJECT, 2022
** move_items
** File description:
** move_items
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"
#include "libmy.h"

int check_item_ype(slot_t *slot)
{
    if (my_strcmp(slot->item->name, "Bow") == 0 ||
        my_strcmp(slot->item->name, "Axe") == 0 ||
        my_strcmp(slot->item->name, "Sword") == 0)
        return 1;
    if (my_strcmp(slot->item->name, "Helmet") == 0)
        return 2;
    if (my_strcmp(slot->item->name, "Armor") == 0)
        return 3;
    if (my_strcmp(slot->item->name, "Gloves") == 0)
        return 4;
    if (my_strcmp(slot->item->name, "Boots") == 0)
        return 5;
    if (my_strcmp(slot->item->name, "Life") == 0 ||
        my_strcmp(slot->item->name, "Food") == 0)
        return 6;
    return 0;
}

void check_slots(inventory_t *inventory, int type, sfVector2i mouse, rpg_t *rpg)
{
    slot_t *slot = NULL;

    for (int i = 0; inventory->slots[i]; i++) {
        slot = inventory->slots[i];
        if (sfFloatRect_contains(&slot->rect->rect, mouse.x, mouse.y))
            type = check_item_ype(slot);
        if (equip_items(slot, type, inventory->slots, rpg) == 1)
            break;
    }
}

void use_items(sfEvent evt, inventory_t *inventory, rpg_t *rpg)
{
    sfVector2i mouse = rpg->window->mouse_pos;
    int type = 0;

    if (!inventory || inventory->showed == 0)
        return;
    if (evt.type == sfEvtMouseButtonPressed &&
        evt.mouseButton.button == sfMouseRight) {
        check_slots(inventory, type, mouse, rpg);
    }
}

void inventory_events(sfEvent evt, inventory_t *inventory, rpg_t *rpg)
{
    if (!(inventory))
        return;
    move_items(evt, inventory, rpg);
    use_items(evt, inventory, rpg);
    quit_item(evt, inventory);
}
