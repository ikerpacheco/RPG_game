/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "libmy.h"
#include "my_rpg.h"

void update_border_view(sfVector2f pos, view_t *view, sfVector2f size)
{
    float height = size.y;
    float width  = size.x;
    float x = pos.x;
    float y = pos.y;

    if (pos.x < width / 2)
        x = width / 2;
    else if (pos.x > (width * 3) - width / 2)
        x  = (width * 3) - width / 2;
    if (pos.y < height / 2)
        y = height / 2;
    else if (pos.y > (height * 3) - height / 2)
        y  = (height * 3) - height / 2;
    sfView_setCenter(view->view, (sfVector2f){x, y});
}

void update_view(entity_t *player, view_t *view)
{
    sfVector2f size = {0, 0};
    sfVector2f center = {0, 0};

    if (!view || !player)
        return;
    size = sfView_getSize(view->view);
    sfView_setCenter(view->view, player->pos->pos);
    update_border_view(player->pos->pos, view, size);
    center = sfView_getCenter(view->view);
    view->pos.x = center.x - size.x / 2;
    view->pos.y = center.y - size.y / 2;
}

void update_game(game_t *game, sfVector2i mouse, float delta)
{
    if (!game->view)
        return;
    update_view(game->player, game->view);
    if (game->player && game->maps[game->i_map]->layer)
        update_player(game->player, delta, game->maps[game->i_map]->layer);
    if (game->maps)
        update_map(game, game->view, delta);
    if (game->quests)
        update_quest(game->quests, game->i_map);
    if (game->inventory)
        update_inventory(game->inventory, game->view, mouse);
    if (game->hud )
        update_hud(game->hud);
}
