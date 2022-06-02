/*
** EPITECH PROJECT, 2022
** equip_items
** File description:
** equip_items
*/

#include "my_rpg.h"
#include "SFML/Graphics.h"

void add_consumable_atr(slot_t *slot, stat_t *stats)
{
    if (!slot->item || !stats || !stats->hp)
        return;
    stats->hp += slot->item->hp;
}

void replace_items(int n2, slot_t *slot, slot_t **slots)
{
    if (slots[n2]->item || !slot->item)
        return;
    slots[n2]->item = slot->item;
    slots[n2]->item->pos->pos.x = slots[n2]->pos->pos.x + 30;
    slots[n2]->item->pos->pos.y = slots[n2]->pos->pos.y + 30;
    slots[n2]->item->pos->applied = sfFalse;
    slot->item = NULL;
}

int equip_items(slot_t *slot, int type, slot_t **slots, rpg_t *rpg)
{
    (void)rpg;
    hud_t *hud = rpg->scenes[GAME]->game->hud;

    if (!slot->item)
        return 0;
    if (type == 6) {
        add_consumable_atr(slot, hud->stats);
        slot->item = NULL;
        return 1;
    }
    for (int i = 1; i <= 5; i++)
        if (type == i)
            replace_items(i + 34, slot, slots);
    return 0;
}