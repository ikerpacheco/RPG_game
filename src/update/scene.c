/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics.h>
#include "libmy.h"
#include "my_rpg.h"

void update_buttons(button_t ***buttons, sfVector2i mouse)
{
    for (int i = 0; buttons[i]; i++)
        for (int j = 0; buttons[i][j]; j++)
            update_button(buttons[i][j], mouse);
}

void update_page(page_t *page, float delta)
{
    if (page->texts)
        for (int i = 0; page->texts[i]; i++)
            update_text(page->texts[i], delta);
    if (page->images)
        for (int i = 0; page->images[i]; i++)
            update_image(page->images[i], delta);
}

void update_pages(page_t **pages, float delta, int page)
{
    if (!pages[page])
        return;
    update_page(pages[page], delta);
}

void update_scene(scene_t *scene, sfVector2i mouse, float delta)
{
    if (scene->bg)
        update_image(scene->bg, delta);
    if (scene->game)
        update_game(scene->game, mouse, delta);
    if (scene->buttons)
        update_buttons(scene->buttons, mouse);
    if (scene->images)
        for (int i = 0; scene->images[i]; i++)
            update_image(scene->images[i], delta);
    if (scene->texts)
        for (int i = 0; scene->texts[i]; i++)
            update_text(scene->texts[i], delta);
    if (scene->pages)
        update_pages(scene->pages, delta, scene->page);
}
