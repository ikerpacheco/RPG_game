/*
** EPITECH PROJECT, 2022
** all_ani
** File description:
** all the functions related to the animation of something
*/

#include <SFML/Graphics.h>
#include "libmy.h"
#include "my_rpg.h"

void run_ani(sfRenderWindow *window, ani_t *ani, render_t *render)
{
    move_rect(&ani->rect, ani->offset, ani->max);
    ani->applied = sfFalse;
    apply_ani(render, ani);
    draw_render(window, render);
    sfRenderWindow_display(window);
    while (ani->rect.top != 0 || ani->rect.left != 0) {
        sfRenderWindow_clear(window, sfBlack);
        move_rect(&ani->rect, ani->offset, ani->max);
        ani->applied = sfFalse;
        apply_ani(render, ani);
        sfSleep((sfTime){ani->time * 1000000});
        draw_render(window, render);
        sfRenderWindow_display(window);
    }
}

void move_rect(sfIntRect *rect, sfVector2i offset, sfVector2i max)
{
    rect->left += offset.x;
    if (rect->left >= max.x) {
        rect->left = 0;
        rect->top += offset.y;
    }
    if (rect->top >= max.y)
        rect->top = 0;
}

void update_ani(ani_t *ani, float delta)
{
    if (ani->i_time == sfTrue)
        return;
    ani->elapsed += delta;
    if (ani->elapsed < ani->time)
        return;
    move_rect(&ani->rect, ani->offset, ani->max);
    ani->elapsed = 0;
    ani->applied = sfFalse;
}

void apply_ani(render_t *render, ani_t *ani)
{
    if (ani->applied)
        return;
    sfSprite_setTextureRect(render->sprite, ani->rect);
    ani->applied = sfTrue;
}
