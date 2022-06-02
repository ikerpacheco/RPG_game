/*
** EPITECH PROJECT, 2022
** music
** File description:
** update music
*/

#include "my_rpg.h"
#include "structs.h"
#include <SFML/Audio.h>

void update_music(music_t *music, int current_map)
{
    static int current = 0;

    if (current != current_map) {
        music->activated = sfFalse;
        sfMusic_stop(music->music);
        current = current_map;
        return;
    }
    if (music->activated == sfFalse) {
        sfMusic_setLoop(music->music, sfTrue);
        sfMusic_play(music->music);
        music->activated = sfTrue;
    }
}
