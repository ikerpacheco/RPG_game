/*
** EPITECH PROJECT, 2022
** draw hud
** File description:
** draw_hud
*/

#include "my_rpg.h"
#include "SFML/Graphics.h"

void draw_inventory(sfRenderWindow *window, inventory_t *inventory)
{
    slot_t *slot = NULL;

    if (!inventory)
        return;
    draw_render(window, inventory->render);
    for (int i = 0; inventory->slots[i] && i < 35; i++) {
        slot = inventory->slots[i];
        if (slot->r_index)
            draw_render(window, slot->render[slot->r_index]);
        if (slot->item && slot->item->render)
            draw_render(window, slot->item->render);
    }
    for (int i = 35; inventory->slots[i]; i++) {
        slot = inventory->slots[i];
        draw_render(window, slot->render[slot->r_index]);
        if (slot->item && slot->item->render)
            draw_render(window, slot->item->render);
    }
}

void draw_hud(hud_t *hud, sfRenderWindow *window)
{
    if (!hud)
        return;
    draw_render(window, hud->hp);
    draw_render(window, hud->attack);
    draw_render(window, hud->defense);
    sfRenderWindow_drawText(window, hud->hp_text->text, NULL);
    sfRenderWindow_drawText(window, hud->att_text->text, NULL);
    sfRenderWindow_drawText(window, hud->def_text->text, NULL);
}
