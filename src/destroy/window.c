/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stdlib.h>
#include "structs.h"

void destroy_window(window_t *window)
{
    if (!window)
        return;
    if (window->window)
        sfRenderWindow_destroy(window->window);
    window->window = NULL;
    if (window)
        free(window);
}
