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

void update_entity_direction(entity_t *entity)
{
    if (entity->move->move.y < 0)
        entity->direction = RIGHT;
    if (entity->move->move.x > 0)
        entity->direction = DOWN;
    if (entity->move->move.x < 0)
        entity->direction = LEFT;
    if (entity->move->move.y > 0)
        entity->direction = UP;
}

sfBool in_range(pos_t *player, pos_t *enemy, float distance)
{
    float dx = enemy->pos.x - player->pos.x;
    float dy = enemy->pos.y - player->pos.y;
    float sqrt = sqrtf(dx * dx + dy * dy);

    if (sqrt <= distance)
        return sfTrue;
    return sfFalse;
}

void follow_player(sfBool full, entity_t *player, entity_t *enemy)
{
    int div = full ? 24 : 16;
    sfVector2f p_pos = {player->pos->pos.x / div, player->pos->pos.y / div};
    sfVector2f e_pos = {enemy->pos->pos.x / div, enemy->pos->pos.y / div};
    sfVector2f next = {0, 0};

    next.x = (p_pos.x < e_pos.x ? e_pos.x - 1 : next.x);
    next.x = (p_pos.x > e_pos.x ? e_pos.x + 1 : next.x);
    next.y = (p_pos.y < e_pos.y ? e_pos.y - 1 : next.y);
    next.y = (p_pos.y > e_pos.y ? e_pos.y + 1 : next.y);
    enemy->move->move.x = 1.2 * (next.x - e_pos.x);
    enemy->move->move.y = 1.2 * (next.y - e_pos.y);
}

void update_enemy_move(entity_t *entity, entity_t *player)
{
    if (!entity->stats->sensor)
        return;
    if (in_range(player->pos, entity->pos, entity->stats->sensor->distance)) {
        follow_player((player->rect->rect.height > 70), player, entity);
    } else {
        entity->move->move.x = (1 + rand() % 2) * ((rand() % 4 ? -1 : -1));
        entity->move->move.y = (1 + rand() % 2) * ((rand() % 5 ? 1 : -1));
    }
    update_entity_direction(entity);
}
