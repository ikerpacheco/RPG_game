/*
** EPITECH PROJECT, 2022
** view
** File description:
** draw view
*/

#include "my_rpg.h"
#include "structs.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/View.h>

void draw_view(sfRenderWindow *window, view_t *view)
{
    sfRenderWindow_setView(window, view->view);
}
