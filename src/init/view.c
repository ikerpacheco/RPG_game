/*
** EPITECH PROJECT, 2022
** view
** File description:
** init view
*/

#include <SFML/Graphics/View.h>
#include "libmy.h"
#include "my_rpg.h"

view_t *init_view(void)
{
    view_t *view = check_malloc(sizeof(view_t));

    if (!view)
        return NULL;
    view->view = sfView_createFromRect((sfFloatRect){0, 0, 1920 / 3, 1080 / 3});
    view->applied = sfFalse;
    return view;
}
