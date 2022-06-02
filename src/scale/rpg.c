/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics/Sprite.h>
#include "my_rpg.h"

void resize_rpg(rpg_t *rpg, int dir)
{
    window_t *window = rpg->window;

    if ((dir && window->size.x == 1920) || (!dir && window->size.x == 1280))
        return;
    window->scale = (window->scale < 0.9 ? 1.0 : 2.0 / 3.0);
    window->scalar = (window->scalar < 0.9 ? 3.0 / 2.0 : 2.0 / 3.0);
    window->size.x = (window->size.x == 1920 ? 1280 : 1920);
    window->size.y = (window->size.y == 1080 ? 720 : 1080);
    window->applied = sfFalse;
    sfRenderWindow_setSize(window->window, window->size);
}

void scale_text(text_t *text, float scalar)
{
    if (text->character_size)
        text->character_size *= scalar;
    text->offset.x *= scalar;
    text->offset.y *= scalar;
    if (text->pos)
        scale_pos(text->pos, scalar);
}

void scale_pages(page_t *page, sfVector2u size, float scale, float scalar)
{
    if (page->buttons)
        for (int i = 0; page->buttons[i]; i++)
            scale_buttons(page->buttons[i], size, scale, scalar);
    if (page->images)
        for (int i = 0; page->images[i]; i++)
            scale_image(page->images[i], scale, scalar);
    if (page->texts)
        for (int i = 0; page->texts[i]; i++)
            scale_text(page->texts[i], scalar);
}

void scale_scene(scene_t *scene, sfVector2u size, float scale, float scalar)
{
    if (scene->bg)
        scale_image(scene->bg, scale, scalar);
    for (int i = 0; scene->buttons && scene->buttons[i]; i++)
        scale_buttons(scene->buttons[i], size, scale, scalar);
    for (int i = 0; scene->images && scene->images[i]; i++)
        scale_image(scene->images[i], scale, scalar);
    if (scene->game)
        scale_game(scene->game, scale, scalar);
    for (int i = 0; scene->pages && scene->pages[i]; i++)
        scale_pages(scene->pages[i], size, scale, scalar);
    for (int i = 0; scene->texts && scene->texts[i]; i++)
        scale_text(scene->texts[i], scale);
    if (scene->editor)
        scale_editor(scene->editor, scalar);
}

void scale_rpg(scene_t **scenes, sfVector2u size, float scale, float scalar)
{
    if (!scenes)
        return;
    for (int i = 0; i < 6; i++)
        if (scenes[i])
            scale_scene(scenes[i], size, scale, scalar);
}
