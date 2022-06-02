/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics/RectangleShape.h>
#include "my_rpg.h"

void scale_editor(editor_t *editor, float scalar)
{
    sfVector2f pos = {0, 0};
    sfVector2f size = {0, 0};

    if (!editor->rects)
        return;
    for (int i = 0; i < 3600; i++) {
        pos = sfRectangleShape_getPosition(editor->rects[i]);
        size = sfRectangleShape_getSize(editor->rects[i]);
        pos.x *= scalar;
        pos.y *= scalar;
        size.x *= scalar;
        size.y *= scalar;
        sfRectangleShape_setPosition(editor->rects[i], pos);
        sfRectangleShape_setSize(editor->rects[i], size);
    }
}
