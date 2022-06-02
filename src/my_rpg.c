/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics/RectangleShape.h>
#include "my_rpg.h"

void draw_editor(sfRenderWindow *window, rpg_t *rpg)
{
    scene_t *scene = rpg->scenes[rpg->i_scene];
    scene_t *game = NULL;
    editor_t *editor = NULL;

    if (!scene || !scene->editor || !rpg->scenes[GAME])
        return;
    if (!(game = rpg->scenes[GAME]) || !(game->game->maps))
        return;
    editor = scene->editor;
    if (game->game->maps[game->game->i_map]->bg)
        draw_render(window, game->game->maps[game->game->i_map]->bg->render);
    for (int i = 0; i < 3600; i++)
        sfRenderWindow_drawRectangleShape(window, editor->rects[i], NULL);
}

void update_editor(rpg_t *rpg)
{
    scene_t *scene = rpg->scenes[rpg->i_scene];
    scene_t *game = NULL;
    int **layer = NULL;
    sfColor blocked = sfColor_fromRGBA(255, 0, 0, 128);
    sfColor open = sfColor_fromRGBA(0, 215, 255, 128);

    if (!scene || !scene->editor || !rpg->scenes[GAME])
        return;
    if (!(game = rpg->scenes[GAME]) || !(game->game->maps))
        return;
    layer = game->game->maps[game->game->i_map]->layer;
    for (int i = 0; i < 3600; i++) {
        if (layer[i / 80][i % 80])
            sfRectangleShape_setFillColor(scene->editor->rects[i], open);
        else
            sfRectangleShape_setFillColor(scene->editor->rects[i], blocked);
    }
}

void game_loop(rpg_t *rpg)
{
    window_t *window = rpg->window;
    int *current = &rpg->i_scene;
    float delta;
    int *language = &rpg->lang;

    while (sfRenderWindow_isOpen(window->window)) {
        if (!window->applied && (window->applied = sfTrue))
            scale_rpg(rpg->scenes, window->size, window->scale, window->scalar);
        window->mouse_pos = sfMouse_getPositionRenderWindow(window->window);
        delta = sfTime_asSeconds(sfClock_restart(rpg->clock));
        sfRenderWindow_clear(window->window, sfBlack);
        if (*current == EDITOR) {
            update_editor(rpg);
            draw_editor(window->window, rpg);
        } else {
            update_scene(rpg->scenes[*current], window->mouse_pos, delta);
            draw_scene(window->window, rpg->scenes[*current], *language);
        }
        event_handling(rpg);
        sfRenderWindow_display(window->window);
    }
}

int my_rpg(void)
{
    rpg_t *rpg = init_rpg();

    if (!rpg)
        return 84;
    game_loop(rpg);
    destroy_rpg(rpg);
    return 0;
}
