/*
** EPITECH PROJECT, 2022
** music
** File description:
** init music
*/

#include "structs.h"
#include "my_rpg.h"
#include "libmy.h"

music_t *init_music(char **arr)
{
    music_t *music = check_malloc(sizeof(music_t));

    if (!music)
        return NULL;
    *music = (music_t){0, NULL, 0};
    music->activated = sfFalse;
    if (*(arr[0]))
        music->music = sfMusic_createFromFile(arr[0]);
    if (*(arr[1]))
        sfMusic_setVolume(music->music, my_atoi(arr[1]));
    return music;
}
