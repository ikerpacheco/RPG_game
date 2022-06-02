/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include "libmy.h"
#include "my_rpg.h"

void assign_function(button_t *button, char **arr)
{
    if (!button || !arr)
        return;
    if (!my_strcmp(arr[0], "change")) {
        button->f = &change_scene;
        button->to = my_atoi(arr[1]);
    }
    if (!my_strcmp(arr[0], "play")) {
        button->f = &change_scene;
        button->to = my_atoi(arr[1]);
    }
    if (!my_strcmp(arr[0], "close"))
        button->f = &close_window;
    if (!my_strcmp(arr[0], "change_page")) {
        button->f = &change_page;
        button->to = my_atoi(arr[1]);
    }
    if (!my_strcmp(arr[0], "language")) {
        button->f = &change_language;
        button->to = my_atoi(arr[1]);
    }
    if (!my_strcmp(arr[0], "scale")) {
        button->f = &resize_rpg;
        button->to = my_atoi(arr[1]);
    }
}

rect_t *init_rect(sfVector2f pos, sfVector2f size)
{
    rect_t *rect = check_malloc(sizeof(rect_t));

    if (!rect)
        return NULL;
    rect->rect = (sfFloatRect){pos.x, pos.y, size.x, size.y};
    return rect;
}

button_t *init_button(sfVector2i gr, sfVector2f si, sfVector2f sep, char **arr)
{
    button_t *button = NULL;
    sfVector2i pos_grid = {my_atoi(arr[0]), my_atoi(arr[1])};

    if (!(button = check_malloc(sizeof(button_t))))
        return NULL;
    *button = (button_t){NULL, 0, NULL, NULL, NULL, NULL, 0};
    if (!(button->render = check_malloc(3 * sizeof(render_t *))))
        return NULL;
    button->grid = get_grid(gr, pos_grid, si, sep);
    button->pos = init_pos(grid_pos((sfVector2u){1920, 1080}, button->grid));
    button->render[0] = init_render(arr[2]);
    button->render[1] = init_render(arr[3]);
    button->render[2] = NULL;
    button->rect = init_rect(button->pos->pos, si);
    for (int i = 0; button->render[i]; i++)
        sfSprite_setPosition(button->render[i]->sprite, button->pos->pos);
    button->r_index = 0;
    return button;
}

button_t **init_button_grid(char **arr, FILE *stream)
{
    sfVector2i grid = {my_atoi(arr[0]), my_atoi(arr[1])};
    int nb = my_atoi(arr[2]);
    sfVector2f sep = {my_atof(arr[5]), my_atof(arr[6])};
    sfVector2f size = {my_atof(arr[3]), my_atof(arr[4])};
    button_t **buttons = NULL;

    if (nb < 0 || !(buttons = check_malloc((nb + 1) * sizeof(button_t *))))
        return NULL;
    for (int i = 0; i < nb; i++) {
        arr = my_stoa(read_line(stream), ':');
        if (my_arrlen(arr) == 7 && !my_strcmp(arr[0], "button"))
            buttons[i] = init_button(grid, size, sep, arr + 1);
        assign_function(buttons[i], arr + 5);
        free(arr);
    }
    buttons[nb] = NULL;
    return buttons;
}

button_t ***init_buttons_grids(char **arr, FILE *stream)
{
    int nb = my_atoi(arr[0]);
    button_t ***buttons = NULL;

    if (nb < 0 || !(buttons = check_malloc((nb + 1) * sizeof(button_t **))))
        return NULL;
    for (int i = 0; i < nb; i++) {
        arr = my_stoa(read_line(stream), ':');
        if (my_arrlen(arr) == 8 && !my_strcmp(arr[0], "grid"))
            buttons[i] = init_button_grid(arr + 1, stream);
    }
    buttons[nb] = NULL;
    return buttons;
}
