/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stddef.h>
#include <stdlib.h>
#include "libmy.h"
#include "my_rpg.h"

window_t *init_window(char **arr)
{
    window_t *window = check_malloc(sizeof(window_t));
    int width = my_atoi(arr[0]);
    int height = my_atoi(arr[1]);

    if (!(window->window = get_window(width, height, arr[2]))) {
        my_puterror("Could not create window\n");
        return NULL;
    }
    window->size = sfRenderWindow_getSize(window->window);
    window->scale = (float)width / 1920;
    window->scalar = (window->scale >= 0.7 ? 1 : 2.0 / 3.0);
    window->applied = sfFalse;
    return window;
}
