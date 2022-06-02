/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** header file structs
*/

#ifndef COMPONENTS_H
    #define COMPONENTS_H

    #include <SFML/Graphics/RenderWindow.h>
    #include <stdbool.h>
    #include <stdio.h>

    typedef struct view_s {
        sfView *view;
        sfVector2f pos;
        sfBool applied;
    } view_t;

    typedef struct t_ani_s {
        char *string;
        float time;
        float elapsed;
        sfBool loop;
        int index;
    } t_ani_t;

    typedef struct hp_s {
        int max;
        int hp;
    } hp_t;

    typedef struct dmg_s {
        int dmg;
        float elapsed;
        float time;
    } dmg_t;

    typedef struct range_t {
        float distance;
    } range_t;

    typedef struct render_s {
        sfBool render;
        sfSprite *sprite;
        sfTexture *texture;
    } render_t;

    typedef struct grid_s {
        sfVector2i grid;
        sfVector2i pos;
        sfVector2f size;
        sfVector2f sep;
    } grid_t;

    typedef struct rect_s {
        sfFloatRect rect;
    } rect_t;

    typedef struct pos_s {
        sfBool applied;
        sfVector2f pos;
    } pos_t;

    typedef struct move_s {
        sfVector2f move;
        float elapsed;
        float time;
    } move_t;

    typedef struct ani_s {
        sfBool applied;
        sfBool i_time;
        sfIntRect rect;
        sfVector2i offset;
        sfVector2i max;
        float elapsed;
        float time;
    } ani_t;

    typedef struct image_s {
        render_t *render;
        pos_t *pos;
        move_t *move;
        ani_t *ani;
    } image_t;

#endif
