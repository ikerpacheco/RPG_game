/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stdlib.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include "structs.h"
#include "my_rpg.h"

void destroy_text(text_t *text)
{
    if (text->font)
        sfFont_destroy(text->font);
    if (text->pos)
        free(text->pos);
    if (text->t_ani)
        free(text->t_ani);
    if (text->text)
        sfText_destroy(text->text);
    free(text);
}

void destroy_page(page_t *page)
{
    if (page->buttons)
        destroy_buttons(page->buttons);
    for (int i = 0; page->images && page->images[i]; i++)
        destroy_image(page->images[i]);
    if (page->images)
        free(page->images);
    for (int i = 0; page->texts && page->texts[i]; i++)
        destroy_text(page->texts[i]);
    if (page->texts)
        free(page->texts);
    free(page);
}

void destroy_scene(scene_t *scene)
{
    if (scene->bg)
        destroy_image(scene->bg);
    if (scene->buttons)
        destroy_buttons(scene->buttons);
    for (int i = 0; scene->images && scene->images[i]; i++)
        destroy_image(scene->images[i]);
    if (scene->images)
        free(scene->images);
    for (int i = 0; scene->pages && scene->pages[i]; i++)
        destroy_page(scene->pages[i]);
    if (scene->pages)
        free(scene->pages);
    for (int i = 0; scene->texts && scene->texts[i]; i++)
        destroy_text(scene->texts[i]);
    if (scene->texts)
        free(scene->texts);
    if (scene->game)
        destroy_game(scene->game);
    free(scene);
}

void destroy_scenes(scene_t **scenes)
{
    if (!scenes)
        return;
    for (int i = 0; scenes[i]; i++)
        destroy_scene(scenes[i]);
    if (scenes)
        free(scenes);
}
