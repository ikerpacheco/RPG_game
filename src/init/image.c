/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include "libmy.h"
#include "my_rpg.h"

static void init_image_ani(image_t * image, char **arr)
{
    sfVector2i offset = {0, 0};
    sfVector2i max = {0, 0};
    sfIntRect rect = {0, 0, 0, 0};
    float dec = 0;

    if (!*(arr[0]) || !*(arr[1]) || !*(arr[2]) || !*(arr[3]) || !*(arr[4]))
        return;
    if (!*(arr[5]) || !*(arr[6]) || !*(arr[7]))
        return;
    rect = (sfIntRect){0, 0, my_atof(arr[1]), my_atof(arr[2])};
    dec = my_atof(arr[7]);
    offset = (sfVector2i){my_atoi(arr[3]), my_atoi(arr[4])};
    max = (sfVector2i){my_atoi(arr[5]), my_atoi(arr[6])};
    if ((image->ani = init_ani(rect, offset, max, dec)))
        image->ani->i_time = (sfBool)my_atoi(arr[0]);
}

image_t *init_image(char **arr)
{
    image_t *image = check_malloc(sizeof(image_t));
    sfVector2f vectorf = {0, 0};

    *image = (image_t){NULL, NULL, NULL, NULL};
    image->render = (*(arr[0]) ? init_render(arr[0]) : NULL);
    if (*(arr[1]) && (*(arr[2])))
        image->pos = init_pos((sfVector2f){my_atof(arr[1]), my_atof(arr[2])});
    if (*(arr[3]) && *(arr[4]) && *(arr[5])) {
        vectorf = (sfVector2f){my_atof(arr[3]), my_atof(arr[4])};
        image->move = init_move(vectorf, my_atof(arr[5]));
    }
    init_image_ani(image, arr + 6);
    return image;
}

image_t **init_image_grid(char **arr, FILE *stream)
{
    int nb = my_atoi(arr[0]);
    image_t **images = check_malloc((nb + 1) * sizeof(image_t *));

    if (!images)
        return NULL;
    for (int i = 0; i < nb; i++) {
        arr = my_stoa(read_line(stream), ':');
        if (my_arrlen(arr) == 15 && !my_strcmp(arr[0], "image"))
            images[i] = init_image(arr + 1);
        free(arr);
    }
    images[nb] = NULL;
    return images;
}
