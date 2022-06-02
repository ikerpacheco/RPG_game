/*
** EPITECH PROJECT, 2022
** apply stats
** File description:
** apply_stats
*/

#include "my_rpg.h"

void add_stats(stat_t *stats, slot_t **slots, int i)
{
    if (stats->hp)
        stats->hp->hp += slots[i]->item->hp;
    if (stats->range)
        stats->range->distance += slots[i]->item->range;
}
