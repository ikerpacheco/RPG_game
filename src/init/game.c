/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stddef.h>
#include <stdlib.h>
#include "libmy.h"
#include "my_rpg.h"

game_t *init_game(FILE *stream)
{
    game_t *game = check_malloc(sizeof(game_t));
    char **arr = NULL;

    if (!game)
        return NULL;
    *game = (game_t){NULL, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    for (char *line = NULL; (line = read_line(stream)); free(arr)) {
        arr = my_stoa(line, ':');
        if (my_arrlen(arr) == 2 && !my_strcmp("maps", arr[0])) {
            game->view = init_view();
            game->maps = init_map_grid(arr + 1, stream);
        }
        if (my_arrlen(arr) == 16 && !my_strcmp(arr[0], "player")) {
            game->player = init_entity(arr + 1);
            game->hud = init_hud(game->player->stats);
        }
        if (my_arrlen(arr) == 2 && !my_strcmp(arr[0], "inventory"))
            game->inventory = init_inventory(arr[1]);
        if (my_arrlen(arr) == 2 && !my_strcmp(arr[0], "quests"))
            game->quests = init_quest_grid(arr + 1, stream);
    }
    return game;
}