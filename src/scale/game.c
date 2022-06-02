/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/View.h>
#include "my_rpg.h"

void scale_item(item_t *item, float scale, float scalar)
{
    if (item->pos)
        scale_pos(item->pos, scalar);
    if (item->render)
        scale_render(item->render, scale);
}

void scale_slot(slot_t *slot, float scale, float scalar)
{
    if (slot->item)
        scale_item(slot->item, scale, scalar);
    if (slot->pos)
        scale_pos(slot->pos, scalar);
    if (slot->rect)
        scale_rect(slot->rect, scalar);
    for (int i = 0; slot->render && slot->render[i]; i++)
        scale_render(slot->render[i], scalar);
}

void scale_inventory(inventory_t *inventory, float scale, float scalar)
{
    inventory->offset.x *= scalar;
    inventory->offset.y *= scalar;
    if (inventory->pos)
        scale_pos(inventory->pos, scalar);
    if (inventory->render)
        scale_render(inventory->render, scale);
    for (int i = 0; inventory->slots && inventory->slots[i]; i++)
        scale_slot(inventory->slots[i], scale, scalar);
}

void scale_view(view_t *view, float scale)
{
    sfVector2f size = {(scale < 1 ? 1280 : 1920), (scale < 1 ? 720 : 1080)};

    size.x /= 3;
    size.y /= 3;
    if (view->view)
        sfView_setSize(view->view, size);
}

void scale_game(game_t *game, float scale, float scalar)
{
    for (int i = 0; game->maps && game->maps[i]; i++)
        scale_map(game->maps[i], scale, scalar);
    if (game->view)
        scale_view(game->view, scale);
    if (game->player)
        scale_entity(game->player, scale, scalar);
    if (game->inventory)
        scale_inventory(game->inventory, scale, scalar);
}
