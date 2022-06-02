/*
** EPITECH PROJECT, 2022
** t_ani
** File description:
** init t_ani
*/

#include <SFML/Graphics/Text.h>
#include "libmy.h"
#include "my_rpg.h"
#include "structs.h"

t_ani_t *init_t_ani(float time, int len)
{
    t_ani_t *t_ani = check_malloc(sizeof(t_ani_t));

    if (!t_ani)
        return NULL;
    *t_ani = (t_ani_t){NULL, 0, 0, 0, 0};
    t_ani->string = my_strmalloc(len);
    t_ani->index = 1;
    t_ani->elapsed = 0;
    t_ani->time = time;
    t_ani->loop = sfFalse;
    return t_ani;
}
