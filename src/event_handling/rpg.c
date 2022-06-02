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

void handle_commands(sfEvent evt, rpg_t *rpg)
{
    game_t *game = rpg->scenes[GAME]->game;
    entity_t *player = NULL;
    object_t **objects = NULL;

    if (game) {
        player = game->player;
        objects = game->maps[game->i_map]->objects;
    }
    switch (evt.key.code) {
        case sfKeyEscape: return change_scene(rpg, MENU);
        case sfKeyE: return change_scene(rpg, EDITOR);
        case sfKeySpace: return make_dialog(objects, player, rpg->lang);
        case sfKeyI: game->inventory->showed ^= 1;
        default: break;
    }
}

void change_scene(rpg_t *rpg, int to)
{
    scene_t *new = rpg->scenes[to];
    window_t *window = rpg->window;
    sfVector2f size = {(float)window->size.x, (float)window->size.y};
    sfSprite *sprite = NULL;
    sfView *view = sfView_createFromRect((sfFloatRect){0, 0, size.x, size.y});

    if (rpg->i_scene == GAME)
        sfRenderWindow_setView(window->window, view);
    if (new->game && new->game->maps)
        sprite = new->game->maps[new->game->i_map]->bg->render->sprite;
    else if (new->bg)
        sprite = new->bg->render->sprite;
    if (sprite)
        transition(window->window, window->size, sprite);
    rpg->prev_scene = rpg->i_scene;
    rpg->i_scene = to;
    sfClock_restart(rpg->clock);
}

void button_events(rpg_t *rpg)
{
    button_t ***buttons = rpg->scenes[rpg->i_scene]->buttons;
    button_t *button = NULL;
    sfVector2i mouse_pos = rpg->window->mouse_pos;
    int i = 0;
    int j = 0;

    if (!buttons)
        return;
    while (buttons[i] && buttons[i][j]) {
        button = buttons[i][j];
        if (sfFloatRect_contains(&button->rect->rect, mouse_pos.x, mouse_pos.y))
            return button->f(rpg, button->to);
        j++;
        if (!buttons[i][j]) {
            i += 1;
            j = 0;
        }
    }
}

void event_handling(rpg_t *rpg)
{
    sfEvent evt;
    int current = rpg->i_scene;

    while (sfRenderWindow_pollEvent(rpg->window->window, &evt)) {
        switch (current) {
            case INTRO: return intro_event_handling(evt, rpg);
            case MENU: return menu_event_handling(evt, rpg);
            case HELP: return help_event_handling(evt, rpg);
            case GAME: return game_event_handling(evt, rpg);
            case SETTINGS: return settings_event_handling(evt, rpg);
            case EDITOR: return editor_event_handling(evt, rpg);
            default: break;
        }
    }
}
