/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>
#include "my_rpg.h"
#include "structs.h"

void modify_layer(rpg_t *rpg)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(rpg->window->window);
    int div = (rpg->window->size.x == 1920 ? 24 : 16);
    int y = mouse_pos.y / div;
    int x = mouse_pos.x / div;
    map_t *map = rpg->scenes[GAME]->game->maps[rpg->scenes[GAME]->game->i_map];
    int **layer = map->layer;

    layer[y][x] ^= 1;
}

void editor_event_handling(sfEvent evt, rpg_t *rpg)
{
    switch (evt.type) {
        case sfEvtClosed: return sfRenderWindow_close(rpg->window->window);
        case sfEvtMouseButtonPressed: return modify_layer(rpg);
        case sfEvtKeyPressed: return change_scene(rpg, GAME);
        default: break;
    }
}
