/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** header file structs
*/

#ifndef MY_RPG_STRUCTS_H
    #define MY_RPG_STRUCTS_H

    #include <SFML/System/Clock.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include "components.h"

    typedef struct hud_s {
        render_t *hp;
        render_t *attack;
        render_t *defense;
        struct text_s *hp_text;
        struct text_s *att_text;
        struct text_s *def_text;
        struct stat_s *stats;
    } hud_t;

    typedef struct slot_s {
        render_t **render;
        rect_t *rect;
        sfVector2f offset;
        struct item_s *item;
        pos_t *pos;
        int r_index;
    } slot_t;

    typedef struct inventory_s {
        render_t *render;
        sfVector2f offset;
        pos_t *pos;
        struct slot_s **slots;
        int first_slot;
        int second_slot;
        sfBool showed;
    } inventory_t;

    typedef struct item_s {
        char *name;
        int id;
        render_t *render;
        int hp;
        int range;
        int damage;
        int att_speed;
        int armor;
        pos_t *pos;
    } item_t;

    typedef struct quest_s {
        int id;
        char *type;
        char *name;
        int map;
        int id_actor;
        int quantity;
        int coins;
        int item;
        sfBool completed;
        sfBool active;
        int author;
    } quest_t;

    typedef struct page_s {
        struct text_s **texts;
        struct image_s **images;
        struct button_s ***buttons;
    } page_t;

    typedef struct music_s {
        sfBool activated;
        sfMusic *music;
        int volume;
    } music_t;

    typedef struct map_s {
        image_t *bg;
        struct door_s **doors;
        int id;
        struct object_s **objects;
        int **layer;
        int max_enemies;
        struct entity_s **enemies;
        struct spawn_s **spawns;
        music_t *music;
    } map_t;

    typedef struct door_s {
        int scene;
        rect_t *rect;
        pos_t *pos;
    } door_t ;

    typedef struct game_s {
        struct entity_s *player;
        int i_map;
        map_t **maps;
        view_t *view;
        struct inventory_s *inventory;
        struct hud_s *hud;
        struct item_s **items;
        struct quest_s **quests;
    } game_t;

    typedef struct spawn_s {
        char **arr;
        float scale;
        float scalar;
        float elapsed;
        float time;
    } spawn_t;

    typedef struct stat_s {
        hp_t *hp;
        dmg_t *dmg;
        range_t *range;
        range_t *sensor;
    } stat_t;

    typedef struct entity_s {
        image_t *image;
        pos_t *pos;
        move_t *move;
        rect_t *rect;
        stat_t *stats;
        int direction;
    } entity_t;

    typedef struct editor_s {
        sfRectangleShape **rects;
    } editor_t;

    typedef struct scene_s {
        int id;
        image_t *bg;
        int page;
        page_t **pages;
        game_t *game;
        editor_t *editor;
        struct text_s **texts;
        struct image_s **images;
        struct button_s ***buttons;
    } scene_t;

    typedef struct text_s {
        sfText *text;
        pos_t *pos;
        char *string;
        sfFont *font;
        float character_size;
        sfColor color;
        sfVector2f offset;
        t_ani_t *t_ani;
        int lang;
    } text_t;

    typedef struct object_s {
        render_t *speaker;
        render_t *chatbox;
        pos_t *pos_s;
        pos_t *pos_c;
        sfVector2f offset_s;
        sfVector2f offset_c;
        int index;
        rect_t *rect;
        struct text_s **texts;
        int quest;
    } object_t;

    typedef struct window_s {
        sfRenderWindow *window;
        float scale;
        float scalar;
        sfBool applied;
        sfVector2u size;
        sfVector2i mouse_pos;
    } window_t;

    typedef struct rpg_s {
        int i_scene;
        int prev_scene;
        sfClock *clock;
        window_t *window;
        scene_t **scenes;
        int lang;
    } rpg_t;

    typedef struct button_s {
        render_t **render;
        int r_index;
        grid_t *grid;
        pos_t *pos;
        rect_t *rect;
        void (*f)(rpg_t *rpg, int to);
        int to;
    } button_t;

#endif
