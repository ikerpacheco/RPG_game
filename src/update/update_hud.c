/*
** EPITECH PROJECT, 2022
** update_hud
** File description:
** update_hud
*/

#include "my_rpg.h"
#include "SFML/Graphics.h"

void update_hud(hud_t *hud)
{
    if (!hud)
        return;
    if (!hud->stats)
        return;
    sfSprite_setPosition(hud->hp->sprite, (sfVector2f){20, 20});
    sfSprite_setPosition(hud->attack->sprite, (sfVector2f){320, 20});
    sfSprite_setPosition(hud->defense->sprite, (sfVector2f){640, 15});
}
