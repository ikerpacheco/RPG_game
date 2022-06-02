/*
** EPITECH PROJECT, 2022
** player
** File description:
** init the player in each scene
*/

#include "libmy.h"
#include "my_rpg.h"

range_t *init_range(float distance)
{
    range_t *range = check_malloc(sizeof(range_t));

    if (!range)
        return NULL;
    *range = (range_t){0};
    range->distance = distance;
    return range;
}

dmg_t *init_dmg(int damage, float time)
{
    dmg_t *dmg = check_malloc(sizeof(dmg_t));

    if (!dmg)
        return NULL;
    *dmg = (dmg_t){0, 0, 0};
    dmg->dmg = damage;
    dmg->elapsed = 0;
    dmg->time = time;
    return dmg;
}

hp_t *init_hp(int stat)
{
    hp_t *hp = check_malloc(sizeof(hp_t));

    if (!hp)
        return NULL;
    hp->hp = stat;
    hp->max = stat;
    return hp;
}

stat_t *init_stats(char *path)
{
    FILE *fp = fopen(path, "r");
    stat_t *stats = check_malloc(sizeof(stat_t));
    char **arr = NULL;

    if (!fp || !stats)
        return NULL;
    *stats = (stat_t){NULL, NULL, NULL, NULL};
    for (char *line = NULL; (line = read_line(fp)); free(arr)) {
        arr = my_stoa(line, ':');
        if (my_arrlen(arr) == 2 && !my_strcmp("hp", arr[0]))
            stats->hp = init_hp(my_atoi(arr[1]));
        if (my_arrlen(arr) == 3 && !my_strcmp("dmg", arr[0]))
            stats->dmg = init_dmg(my_atoi(arr[1]), my_atof(arr[2]));
        if (my_arrlen(arr) == 2 && !my_strcmp("sensor", arr[0]))
            stats->sensor = init_range(my_atof(arr[1]));
        if (my_arrlen(arr) == 2 && !my_strcmp("range", arr[0]))
            stats->range = init_range(my_atof(arr[1]));
    }
    return stats;
}
