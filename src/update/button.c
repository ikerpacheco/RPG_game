/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/System/Sleep.h>
#include "libmy.h"
#include "my_rpg.h"

void change_language(rpg_t *rpg, int to)
{
    rpg->lang = to;
}

void change_page(rpg_t *rpg, int dir)
{
    int *index = &rpg->scenes[rpg->i_scene]->page;
    page_t **pages = rpg->scenes[rpg->i_scene]->pages;
    ani_t *ani = rpg->scenes[rpg->i_scene]->bg->ani;
    sfRenderWindow *window = rpg->window->window;
    render_t *render = rpg->scenes[rpg->i_scene]->bg->render;

    if ((dir == 1 && !pages[*index]) || (dir == 0 && *index == 0))
        return;
    run_ani(window, ani, render);
    *index += (dir ? 1 : -1);
}

void close_window(rpg_t *rpg, int null)
{
    sfRenderWindow_close(rpg->window->window);
    (void)null;
}

void update_button(button_t *button, sfVector2i mouse)
{
    int *i = NULL;

    if (!button)
        return;
    i = &button->r_index;
    if (button->render) {
        *i = (int)sfFloatRect_contains(&button->rect->rect, mouse.x, mouse.y);
        for (int j = 0; button->render[j]; j++) {
            button->render[j]->render = sfFalse;
            apply_pos(button->pos, button->render[j]);
            button->pos->applied = sfFalse;
        }
        button->render[*i]->render = sfTrue;
    }
}
