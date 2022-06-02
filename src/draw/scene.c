/*
** EPITECH PROJECT, 2022
** draw_scene
** File description:
** drawing the current scene
*/

#include <SFML/Graphics.h>
#include "libmy.h"
#include "my_rpg.h"

void draw_text(sfRenderWindow* window, text_t* text, int lang)
{
    if (lang == text->lang)
        sfRenderWindow_drawText(window, text->text, NULL);
}

void draw_render(sfRenderWindow *window, render_t *render)
{
    if (!render->render)
        return;
    sfRenderWindow_drawSprite(window, render->sprite, NULL);
}

void draw_buttons(sfRenderWindow *window, button_t ***buttons)
{
    button_t *button = NULL;

    if (!buttons)
        return;
    for (int i = 0; buttons[i]; i++)
        for (int j = 0; buttons[i][j]; j++) {
            button = buttons[i][j];
            draw_render(window, button->render[button->r_index]);
        }
}

void draw_pages(sfRenderWindow *window, page_t **pages, int i_page, int lang)
{
    page_t *page = NULL;

    if (!pages[i_page])
        return;
    page = pages[i_page];
    for (int j = 0; page->texts && page->texts[j]; j++)
        draw_text(window, page->texts[j], lang);
    for (int j = 0; page->images && page->images[j]; j++)
        draw_render(window, page->images[j]->render);
}

void draw_scene(sfRenderWindow *window, scene_t *scene, int lang)
{
    if (scene->bg)
        draw_render(window, scene->bg->render);
    if (scene->game)
        draw_game(window, scene->game, lang);
    if (scene->images || scene->texts) {
        for (int j = 0; scene->images && scene->images[j]; j++)
            draw_render(window, scene->images[j]->render);
        for (int j = 0; scene->texts && scene->texts[j]; j++)
            draw_text(window, scene->texts[j], lang);
    }
    if (scene->pages)
        draw_pages(window, scene->pages, scene->page, lang);
    if (scene->buttons)
        draw_buttons(window, scene->buttons);
}
