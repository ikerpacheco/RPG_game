/*
** EPITECH PROJECT, 2022
** draw_scene
** File description:
** drawing the current scene
*/

#include <SFML/Graphics.h>
#include "libmy.h"
#include "my_rpg.h"

void make_dialog(object_t **objects, entity_t *player, int lang)
{
    sfVector2f pos = player->pos->pos;
    object_t *obj = NULL;
    int new_i = 0;

    if (!objects)
        return;
    for (int i = 0; objects[i]; i++) {
        obj = objects[i];
        new_i = obj->index + 1;
        for (; obj->texts[new_i] && obj->texts[new_i]->lang != lang; new_i++);
        if (sfFloatRect_contains(&obj->rect->rect, pos.x, pos.y))
            obj->index = obj->texts[new_i] ? new_i : -1;
    }
}

void draw_object(sfRenderWindow *window, object_t *object, int lang)
{
    if (object->index == -1)
        return;
    draw_render(window, object->chatbox);
    draw_render(window, object->speaker);
    draw_text(window, object->texts[object->index], lang);
}

void draw_map(sfRenderWindow *window, map_t *map, int lang)
{
    if (map->bg)
        draw_render(window, map->bg->render);
    for (int i = 0; map->enemies && map->enemies[i]; i++)
        draw_render(window, map->enemies[i]->image->render);
    for (int i = 0; map->objects && map->objects[i]; i++)
        draw_object(window, map->objects[i], lang);
}

void draw_game(sfRenderWindow *window, game_t *game, int lang)
{
    if (game->view)
        draw_view(window, game->view);
    if (game->maps && game->player)
        draw_map(window, game->maps[game->i_map], lang);
    if (game->player)
        draw_render(window, game->player->image->render);
    if (game->inventory && game->inventory->showed)
        draw_inventory(window, game->inventory);
}
