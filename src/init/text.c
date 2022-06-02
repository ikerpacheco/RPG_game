/*
** EPITECH PROJECT, 2022
** text
** File description:
** init text structure
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "libmy.h"
#include "my_rpg.h"

text_t *init_text(char **arr)
{
    text_t *text = check_malloc(sizeof(text_t));

    if (!text)
        return NULL;
    *text = (text_t){NULL, NULL, NULL, NULL, 0, {0, 0, 0, 0}, {0, 0}, NULL, 0};
    if (*(arr[0]) && *(arr[4]))
        text->t_ani = init_t_ani(my_atof(arr[0]), my_strlen(arr[4]));
    text->text = sfText_create();
    if (*(arr[1]))
        text->lang = my_atoi(arr[1]);
    if (*(arr[2]) && *(arr[3]) && *(arr[4])) {
        text->font = sfFont_createFromFile(arr[2]);
        text->character_size = my_atof(arr[3]);
        text->string = arr[4];
    }
    if (*(arr[5]) && *(arr[6]) && *(arr[7]) && *arr[8])
        text->color = sfColor_fromRGBA(my_atoi(arr[5]),
        my_atoi(arr[6]), my_atoi(arr[7]), my_atoi(arr[8]));
    if (*(arr[9]) && *(arr[10]))
        text->offset = (sfVector2f){my_atof(arr[9]), my_atof(arr[10])};
    text->pos = init_pos(text->offset);
    return text;
}

text_t **init_text_grid(char **arr, FILE *stream)
{
    int nb = my_atoi(arr[0]);
    text_t **texts = NULL;

    if (!(texts = check_malloc((nb + 1) * sizeof(text_t *))))
        return NULL;
    for (int i = 0; i < nb; i++) {
        arr = my_stoa(read_line(stream), ':');
        if (my_arrlen(arr) == 12 && !my_strcmp(arr[0], "text"))
            texts[i] = init_text(arr + 1);
        free(arr);
    }
    texts[nb] = NULL;
    return texts;
}
