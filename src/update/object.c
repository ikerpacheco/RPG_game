/*
** EPITECH PROJECT, 2022
** object
** File description:
** update objects
*/

#include "my_rpg.h"
#include "structs.h"
#include <SFML/Graphics.h>

void check_quest(object_t *object, quest_t **quests, pos_t *pos)
{
    if (!object || object->index == -1 || !quests)
        return;
    if (!sfFloatRect_contains(&object->rect->rect, pos->pos.x, pos->pos.y))
        return;
    if (object->quest)
        quests[object->quest - 1]->active = sfTrue;
}

void update_object(object_t *object, view_t *view, float delta)
{
    if (!object)
        return;
    if (object->chatbox && object->pos_c) {
        update_pos_view(view, object->pos_c, object->offset_c);
        apply_pos(object->pos_c, object->chatbox);
    }
    if (object->speaker && object->pos_s) {
        update_pos_view(view, object->pos_s, object->offset_s);
        apply_pos(object->pos_s, object->speaker);
    }
    if (object->index == -1)
        return;
    if (object->texts)
        update_text(object->texts[object->index], delta);
    for  (int i = 0; object->texts && object->texts[i]; i++) {
        update_pos_view(view, object->texts[i]->pos, object->texts[i]->offset);
        sfText_setPosition(object->texts[i]->text, object->texts[i]->pos->pos);
    }
}
