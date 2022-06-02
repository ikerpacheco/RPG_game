/*
** EPITECH PROJECT, 2022
** hud
** File description:
** hud
*/

#include <SFML/Graphics.h>
#include "libmy.h"
#include "my_rpg.h"

hud_t *init_hud_stats(hud_t *hud)
{
    if (!hud)
        return NULL;
    hud->hp_text->text = sfText_create();
    hud->att_text->text = sfText_create();
    hud->def_text->text = sfText_create();
    hud->hp_text->character_size = 20;
    hud->att_text->character_size = 20;
    hud->def_text->character_size = 20;
    hud->hp_text->font = sfFont_createFromFile("assets/text/fon3.ttf");
    hud->att_text->font = sfFont_createFromFile("assets/text/fon3.ttf");
    hud->def_text->font = sfFont_createFromFile("assets/text/fon3.ttf");
    hud->hp_text->color = sfWhite;
    hud->att_text->color = sfWhite;
    hud->def_text->color = sfWhite;
    return hud;
}

hud_t *init_hud(stat_t *player_stats)
{
    hud_t *hud = NULL;

    if (!(hud = check_malloc(sizeof(hud_t))))
        return NULL;
    *hud = (hud_t){NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    hud->hp = init_render("assets/hud/resize/life.png");
    hud->attack = init_render("assets/hud/resize/attack.png");
    hud->defense = init_render("assets/hud/resize/armor.png");
    hud->hp_text = check_malloc(sizeof(text_t));
    hud->att_text = check_malloc(sizeof(text_t));
    hud->def_text = check_malloc(sizeof(text_t));
    hud->stats = player_stats;
    init_hud_stats(hud);
    return hud;
}