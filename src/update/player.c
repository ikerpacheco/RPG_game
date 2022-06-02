/*
** EPITECH PROJECT, 2022
** player
** File description:
** player
*/

#include <SFML/Graphics/Sprite.h>
#include "my_rpg.h"
#include "structs.h"

void check_collision(sfFloatRect rect, pos_t *pos_s, move_t *move_s, int **layer)
{
    sfVector2f move = move_s->move;
    sfVector2f pos = {pos_s->pos.x, pos_s->pos.y + 2 * rect.height / 3};
    int div = (rect.height >= 60 ? 24 : 16);
    int x = (int)pos.x / div;
    int y = (int)pos.y / div;

    rect.height /= 3;
    if (move.x)
        x = (int)(pos.x + move.x + (move.x > 0 ? rect.width / 2 : 0)) / div;
    if (move.y)
        y = (int)(pos.y + move.y + (move.y > 0 ? rect.height / 2: 0)) / div;
    if (move.x || move.y)
        if (x < 0 || x >= 80 || y < 0 || y >= 45 || layer[y][x] == 0)
            move_s->move = (sfVector2f){0, 0};
}

void update_player_move(entity_t *player)
{
    if (sfKeyboard_isKeyPressed(sfKeyW))
        player->move->move.y = -2;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        player->move->move.x = 2;
    if (sfKeyboard_isKeyPressed(sfKeyA))
        player->move->move.x = -2;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        player->move->move.y = 2;
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        player->move->move.x *= 1.5;
        player->move->move.y *= 1.5;
    }
    update_entity_direction(player);
}

void move_anim(ani_t *ani, float delta, int direction)
{
    ani->elapsed += delta;
    ani->rect.top = direction;
    ani->applied = sfFalse;
    if (ani->elapsed < ani->time)
        return;
    ani->rect.left += ani->offset.x;
    if (ani->rect.left >= ani->max.x)
        ani->rect.left = 0;
    ani->elapsed = 0;
}

void update_player(entity_t *player, float delta, int **layer)
{
    ani_t *ani = NULL;

    if (!player)
        return;
    if (player->move)
        update_player_move(player);
    ani = player->image->ani;
    check_collision(player->rect->rect, player->pos, player->move, layer);
    if (ani && (player->move->move.x || player->move->move.y))
        move_anim(ani, delta, player->direction * ani->rect.height);
    if (player->move && player->pos)
        update_pos(player->move, player->pos, delta);
    if (player->pos && player->image->render)
        apply_pos(player->pos, player->image->render);
    if (player->image->render && player->image->ani)
        apply_ani(player->image->render, player->image->ani);
    player->move->move = (sfVector2f){0, 0};
}
