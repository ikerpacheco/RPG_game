/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stdlib.h>
#include <SFML/Graphics/View.h>
#include "structs.h"
#include "my_rpg.h"

void destroy_view(view_t *view)
{
    if (view->view)
        sfView_destroy(view->view);
    free(view);
}

void destroy_player(entity_t *player)
{
    if (player->image)
        destroy_image(player->image);
    free(player);
}

void destroy_game(game_t *game)
{
    for (int i = 0; game->maps && game->maps[i]; i++)
        destroy_map(game->maps[i]);
    if (game->maps)
        free(game->maps);
    if (game->player)
        destroy_player(game->player);
    if (game->view)
        destroy_view(game->view);
    free(game);
}
