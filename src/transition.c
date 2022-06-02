/*
** EPITECH PROJECT, 2022
** transition
** File description:
** transition between scenes
*/

#include <SFML/Graphics.h>
#include "my_rpg.h"
#include "structs.h"

void transition(sfRenderWindow *window, sfVector2u size, sfSprite *sprite)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfBool opening = sfFalse;
    float r = 1250;
    sfVector2f pos = {((float)size.x / 2) - r, ((float)size.y / 2) - r};

    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setOutlineThickness(circle, 1500);
    sfCircleShape_setOutlineColor(circle, sfBlack);
    while (!sfKeyboard_isKeyPressed(sfKeySpace) && r < 1300) {
        sfCircleShape_setRadius(circle, r);
        pos = (sfVector2f){(size.x / 2) - r, (size.y / 2) - r};
        sfCircleShape_setPosition(circle, pos);
        if (opening)
            sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawCircleShape(window, circle, NULL);
        sfRenderWindow_display(window);
        opening = (r <= -50 ? sfTrue : opening);
        r += (opening ? 50 : -50);
    }
}
