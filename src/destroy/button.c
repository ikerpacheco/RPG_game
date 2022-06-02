/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stdlib.h>
#include "structs.h"
#include "my_rpg.h"

void destroy_button(button_t *button)
{
    if (!button)
        return;
    if (button->render) {
        for (int i = 0; button->render[i]; i++)
            destroy_render(button->render[i]);
        free(button->render);
    }
    if (button->rect)
        free(button->rect);
    if (button->grid)
        free(button->grid);
    if (button->pos)
        free(button->pos);
    free(button);
}

void destroy_buttons(button_t ***buttons)
{
    for (int i = 0; buttons[i]; i++) {
        for (int j = 0; buttons[i][j]; j++)
            destroy_button(buttons[i][j]);
        free(buttons[i]);
    }
    free(buttons);
}
