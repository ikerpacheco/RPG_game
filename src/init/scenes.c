/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include "libmy.h"
#include "my_rpg.h"

void fill_scene(scene_t *scene, char **arr, FILE *stream)
{
    if (my_arrlen(arr) == 15 && !my_strcmp(arr[0], "bg"))
        scene->bg = init_image(arr + 1);
    if (my_arrlen(arr) == 2 && !my_strcmp(arr[0], "buttons_grids"))
        scene->buttons = init_buttons_grids(arr + 1, stream);
    if (!my_strcmp(arr[0], "pages"))
        scene->pages = init_pages(arr + 1);
    if (my_arrlen(arr) == 2 && !my_strcmp("images", arr[0]))
        scene->images = init_image_grid(arr + 1, stream);
    if (my_arrlen(arr) == 2 && !my_strcmp("texts", arr[0]))
        scene->texts = init_text_grid(arr + 1, stream);
    if (my_arrlen(arr) == 1 && !my_strcmp("game", arr[0]))
        scene->game = init_game(stream);
    if (my_arrlen(arr) == 1 && !my_strcmp("editor", arr[0]))
        scene->editor = init_editor();
}

scene_t *scene_from_path(char *path)
{
    FILE *stream = fopen(path, "r");
    scene_t *sc = check_malloc(sizeof(scene_t));
    char **arr = NULL;

    if (!sc)
        return NULL;
    *sc = (scene_t){0, NULL, 0, NULL, NULL, NULL, NULL, NULL, NULL};
    for (char *line = NULL; (line = read_line(stream)); free(arr)) {
        arr = my_stoa(line, ':');
        fill_scene(sc, arr, stream);
    }
    fclose(stream);
    return sc;
}

scene_t **init_scenes(char *path)
{
    FILE *stream = fopen(path, "r");
    int nb_scenes = my_atoi(read_line(stream));
    scene_t **scenes = check_malloc((nb_scenes + 1) * sizeof(scene_t *));
    char **arr = NULL;

    if (!scenes || !stream)
        return NULL;
    for (int i = 0; i < nb_scenes; i++) {
        arr = my_stoa(read_line(stream), ':');
        if (my_arrlen(arr) == 2)
            scenes[i] = scene_from_path(arr[1]);
    }
    scenes[nb_scenes] = NULL;
    fclose(stream);
    return scenes;
}
