/*
** EPITECH PROJECT, 2022
** text
** File description:
** text
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include "libmy.h"
#include "my_rpg.h"

void apply_pos_text(pos_t *pos, sfText *text)
{
    if (pos->applied)
        return;
    sfText_setPosition(text, pos->pos);
    pos->applied = true;
}

void update_t_ani(t_ani_t *t_ani, char *string, float delta)
{
    if (!my_strcmp(string, t_ani->string)) {
        if (!t_ani->loop)
            return;
        t_ani->string = my_strmalloc(my_strlen(t_ani->string));
        t_ani->index = 1;
    }
    if (t_ani->index >= my_strlen(string))
        return;
    t_ani->string[0] = string[0];
    t_ani->elapsed += delta;
    if (t_ani->elapsed < t_ani->time)
        return;
    t_ani->elapsed = 0;
    t_ani->string[t_ani->index] = string[t_ani->index];
    t_ani->index++;
}

void set_string(sfText *text, char *string, t_ani_t *t_ani)
{
    char *str = NULL;

    if (t_ani && *(t_ani->string))
        str = t_ani->string;
    else
        str = string;
    sfText_setString(text, str);
}

void update_text(text_t *text, float delta)
{
    if (!text->text)
        return;
    sfText_setColor(text->text, text->color);
    sfText_setCharacterSize(text->text, (int)text->character_size);
    sfText_setFont(text->text, text->font);
    apply_pos_text(text->pos, text->text);
    if (text->t_ani)
        update_t_ani(text->t_ani, text->string, delta);
    set_string(text->text, text->string, text->t_ani);
}
