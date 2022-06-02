/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stdlib.h>
#include <SFML/Graphics/RectangleShape.h>
#include "libmy.h"
#include "my_rpg.h"

editor_t *init_editor(void)
{
    editor_t *editor = check_malloc(sizeof(editor_t));
    float left = 0;
    float top = 0;
    float width = 24;
    float height = 24;
    sfRectangleShape **shapes = check_malloc(sizeof(sfRectangleShape *) * 3601);

    if (!editor || !shapes)
        return NULL;
    for (int i = 0; i < 3600; i++) {
        left = i % 80 * width;
        top = i / 80 * height;
        shapes[i] = sfRectangleShape_create();
        sfRectangleShape_setPosition(shapes[i], (sfVector2f){left, top});
        sfRectangleShape_setSize(shapes[i], (sfVector2f){width, height});
    }
    editor->rects = shapes;
    return editor;
}
