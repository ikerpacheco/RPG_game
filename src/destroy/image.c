/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <stdlib.h>
#include "structs.h"

void destroy_render(render_t *render)
{
    if (!render)
        return;
    if (render->sprite)
        sfSprite_destroy(render->sprite);
    if (render->texture)
        sfTexture_destroy(render->texture);
    free(render);
}

void destroy_image(image_t *image)
{
    if (!image)
        return;
    if (image->ani)
        free(image->ani);
    if (image->move)
        free(image->move);
    if (image->pos)
        free(image->pos);
    if (image->render)
        destroy_render(image->render);
    free(image);
}
