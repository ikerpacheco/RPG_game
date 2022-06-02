/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** header file prototypes
*/

#ifndef MY_RPG_H
    #define MY_RPG_H

    #include <stdio.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include "structs.h"

    enum {
        INTRO,
        MENU,
        HELP,
        GAME,
        SETTINGS,
        EDITOR
    };

    enum {
        UP,
        LEFT,
        DOWN,
        RIGHT
    };

    void apply_stats(rpg_t *rpg, slot_t **slots);
    void apply_pos(pos_t *pos, render_t *render);
    hud_t *init_hud(stat_t *player_stats);
    void update_hud(hud_t *hud);
    void draw_hud(hud_t *hud, sfRenderWindow *window);
    int equip_items(slot_t *slot, int type, slot_t **slots, rpg_t *rpg);
    void update_item(item_t *item);
    void add_item(rpg_t *rpg);
    void apply_ani(render_t *render, ani_t *ani);
    void inventory_events(sfEvent evt, inventory_t *inventory, rpg_t *rpg);
    void update_items(item_t **items);
    int check_item_ype(slot_t *slot);
    void quit_item(sfEvent evt, inventory_t *inventory);
    item_t **init_items(char **arr, FILE *stream);
    inventory_t *init_inventory(char *path);
    void move_items(sfEvent evt, inventory_t *inventory, rpg_t *rpg);
    void update_slot(slot_t *slot, view_t *view, sfVector2i mouse_pos);
    void add_item(rpg_t *rpg);
    slot_t **init_slots(char **arr);
    void assign_function(button_t *button, char **arr);
    void button_events(rpg_t *rpg);
    void change_language(rpg_t *rpg, int to);
    void change_page(rpg_t *rpg, int dir);
    void change_scene(rpg_t *rpg, int to);
    void check_collision(sfFloatRect, pos_t *, move_t *, int **);
    void check_quest(object_t *object, quest_t **quests, pos_t *pos);
    void close_window(rpg_t *rpg, int null);
    void destroy_buttons(button_t ***buttons);
    void destroy_door(door_t *door);
    void destroy_game(game_t *game);
    void destroy_image(image_t *image);
    void destroy_map(map_t *map);
    void destroy_object(object_t *object);
    void destroy_render(render_t *render);
    void destroy_rpg(rpg_t *rpg);
    void destroy_scenes(scene_t **scenes);
    void destroy_text(text_t *text);
    void destroy_window(window_t *window);
    void draw_game(sfRenderWindow *window, game_t *game, int lang);
    void draw_inventory(sfRenderWindow *window, inventory_t *inventory);
    void draw_map(sfRenderWindow *window, map_t *map, int lang);
    void draw_object(sfRenderWindow *, object_t *, int lang);
    void draw_objects(sfRenderWindow *, object_t **, sfVector2f);
    void draw_render(sfRenderWindow *window, render_t *render);
    void draw_scene(sfRenderWindow *window, scene_t *scene, int lang);
    void draw_slot(sfRenderWindow *window, slot_t *slot);
    void draw_text(sfRenderWindow *, text_t *text, int lang);
    void draw_view(sfRenderWindow *window, view_t *view);
    void editor_event_handling(sfEvent evt, rpg_t *rpg);
    void event_handling(rpg_t *rpg);
    void game_event_handling(sfEvent evt, rpg_t *rpg);
    sfRenderWindow *get_window(int x, int y, char *name);
    grid_t *get_grid(sfVector2i, sfVector2i, sfVector2f, sfVector2f);
    sfVector2f grid_pos(sfVector2u size, grid_t *grid);
    void handle_commands(sfEvent evt, rpg_t *rpg);
    void help_event_handling(sfEvent evt, rpg_t *rpg);
    sfBool in_range(pos_t *player, pos_t *enemy, float distance);
    ani_t *init_ani(sfIntRect, sfVector2i, sfVector2i, float);
    button_t ***init_buttons_grids(char **arr, FILE *stream);
    door_t **init_door_grid(char **arr, FILE *stream);
    editor_t *init_editor(void);
    entity_t *init_entity(char **array);
    game_t *init_game(FILE *stream);
    image_t *init_image(char **arr);
    image_t **init_image_grid(char **arr, FILE *stream);
    map_t **init_map_grid(char **arr, FILE *stream);
    move_t *init_move(sfVector2f move_v, float time);
    music_t *init_music(char **arr);
    object_t **init_object_grid(char **arr, FILE *stream);
    page_t **init_pages(char **array);
    pos_t *init_pos(sfVector2f pos_v);
    quest_t **init_quest_grid(char **arr, FILE *stream);
    rect_t *init_rect(sfVector2f pos, sfVector2f size);
    render_t *init_render(char *path);
    rpg_t *init_rpg(void);
    scene_t **init_scenes(char *path);
    stat_t *init_stats(char *path);
    t_ani_t *init_t_ani(float time, int len);
    text_t **init_text_grid(char **array, FILE *stream);
    int **init_tiles(char *layer);
    view_t *init_view(void);
    window_t *init_window(char **arr);
    void make_dialog(object_t **objects, entity_t *player, int lang);
    void intro_event_handling(sfEvent evt, rpg_t *rpg);
    void menu_event_handling(sfEvent evt, rpg_t *rpg);
    void move_anim(ani_t *ani, float delta, int direction);
    void move_rect(sfIntRect *rect, sfVector2i offset, sfVector2i max);
    int my_rpg(void);
    void resize_rpg(rpg_t *rpg, int dir);
    void run_ani(sfRenderWindow *window, ani_t *ani, render_t *render);
    void scale_buttons(button_t **, sfVector2u, float, float);
    void scale_game(game_t *game, float scale, float scalar);
    void scale_grid(grid_t *grid, float scalar);
    void scale_image(image_t *image, float scale, float scalar);
    void scale_map(map_t *map, float scale, float scalar);
    void scale_move(move_t *move, float scalar);
    void scale_editor(editor_t *editor, float scalar);
    void scale_entity(entity_t *player, float scale, float scalar);
    void scale_pos(pos_t *pos, float scalar);
    void scale_rect(rect_t *rect, float scalar);
    void scale_render(render_t *render, float scale);
    void scale_rpg(scene_t **, sfVector2u, float, float);
    void scale_text(text_t *text, float scalar);
    void scale_view(view_t *view, float scale);
    void settings_event_handling(sfEvent evt, rpg_t *rpg);
    void start_game(rpg_t *rpg, int to);
    void transition(sfRenderWindow *window, sfVector2u size, sfSprite *sprite);
    void update_ani_player(ani_t *ani, float delta, int direction);
    void update_inventory(inventory_t *, view_t *, sfVector2i);
    void update_ani(ani_t *ani, float delta);
    void update_button(button_t *button, sfVector2i mouse_pos);
    void update_dialog(t_ani_t *t_ani, char *string, float delta);
    void update_enemy(entity_t *, entity_t *, int **, float);
    void update_enemy_move(entity_t *entity, entity_t *player);
    void update_entity_direction(entity_t *entity);
    void update_game(game_t *game, sfVector2i mouse_pos, float delta);
    void update_image(image_t *image, float delta);
    void update_map(game_t *game, view_t *view, float delta);
    void update_music(music_t *music, int current_map);
    void update_player(entity_t *player, float delta, int **layer);
    void update_quest(quest_t **quests, int current_map);
    void update_object(object_t *object, view_t *view, float delta);
    void update_pos(move_t *move, pos_t *pos, float delta);
    void update_pos_view(view_t *view, pos_t *pos, sfVector2f offset);
    void update_scene(scene_t *scene, sfVector2i mouse_pos, float delta);
    void update_text(text_t *text, float delta);
    void update_view(entity_t *player, view_t *view);
    int usage(void);

#endif
