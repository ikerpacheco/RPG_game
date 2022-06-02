/*
** EPITECH PROJECT, 2022
** map
** File description:
** update map
*/

#include <stdlib.h>
#include <math.h>
#include "my_rpg.h"
#include "structs.h"

void attack(entity_t *attacker, entity_t *attacked, float delta)
{
    if (!attacker || !attacker->stats)
        return;
    if (!attacked || !attacked->stats)
        return;
    if (!attacker->stats->dmg)
        return;
    attacker->stats->dmg->elapsed += delta;
    if (attacker->stats->dmg->elapsed < attacker->stats->dmg->time)
        return;
    if (!attacked->stats->hp)
        return;
    attacked->stats->hp->hp -= attacker->stats->dmg->dmg;
}

void update_enemy(entity_t *enemy, entity_t *player, int **layer, float delta)
{
    ani_t *ani = NULL;

    if (!enemy)
        return;
    ani = enemy->image->ani;
    if ((!enemy->move->move.x && !enemy->move->move.y) || enemy->stats->sensor)
        update_enemy_move(enemy, player);
    check_collision(enemy->rect->rect, enemy->pos, enemy->move, layer);
    if (ani && (enemy->move->move.x || enemy->move->move.y))
        move_anim(ani, delta, enemy->direction * ani->rect.height);
    if (in_range(player->pos, enemy->pos, enemy->stats->range->distance))
        attack(enemy, player, delta);
    if (enemy->move && enemy->image->pos)
        update_pos(enemy->move, enemy->image->pos, delta);
    if (enemy->image->pos && enemy->image->render)
        apply_pos(enemy->image->pos, enemy->image->render);
    if (enemy->image->render && enemy->image->ani)
        apply_ani(enemy->image->render, enemy->image->ani);
}
