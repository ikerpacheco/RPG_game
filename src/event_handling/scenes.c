/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics/RenderWindow.h>
#include "my_rpg.h"
#include "structs.h"

void intro_event_handling(sfEvent evt, rpg_t *rpg)
{
    switch (evt.type) {
        case sfEvtClosed: sfRenderWindow_close(rpg->window->window);
            break;
        case sfEvtKeyPressed: change_scene(rpg, MENU);
            break;
        default: break;
    }
}

void settings_event_handling(sfEvent evt, rpg_t *rpg)
{
    switch (evt.type) {
        case sfEvtClosed: sfRenderWindow_close(rpg->window->window);
            break;
        case sfEvtMouseButtonPressed: button_events(rpg);
            break;
        case sfEvtKeyPressed: change_scene(rpg, rpg->prev_scene);
            break;
        default: break;
    }
}

void menu_event_handling(sfEvent evt, rpg_t *rpg)
{
    switch (evt.type) {
        case sfEvtClosed: sfRenderWindow_close(rpg->window->window);
            break;
        case sfEvtMouseButtonPressed: button_events(rpg);
            break;
        default: break;
    }
}

void help_event_handling(sfEvent evt, rpg_t *rpg)
{
    switch (evt.type) {
        case sfEvtClosed: sfRenderWindow_close(rpg->window->window);
            break;
        case sfEvtMouseButtonPressed: button_events(rpg);
            break;
        case sfEvtKeyPressed: change_scene(rpg, MENU);
            break;
        default: break;
    }
}

void game_event_handling(sfEvent evt, rpg_t *rpg)
{
    switch (evt.type) {
        case sfEvtClosed: sfRenderWindow_close(rpg->window->window);
            break;
        case sfEvtMouseButtonPressed: button_events(rpg);
            break;
        case sfEvtKeyPressed: handle_commands(evt, rpg);
            break;
        default: break;
    }
}
