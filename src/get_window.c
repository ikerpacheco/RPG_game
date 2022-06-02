/*
** EPITECH PROJECT, 2021
** my_defender
** File description:
** function that initializes a window at 30fps
*/

#include <SFML/Graphics/RenderWindow.h>

sfRenderWindow *get_window(int x, int y, char *name)
{
    sfVideoMode video_mode = sfVideoMode_getDesktopMode();
    unsigned int width = video_mode.width;
    unsigned int height = video_mode.height;
    sfVector2i pos = {(width - x) / 2, (height - y) / 2};
    sfRenderWindow *window;

    video_mode.width = x;
    video_mode.height = y;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, name, sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setPosition(window, pos);
    return window;
}
