/*
** EPITECH PROJECT, 2022
** pages
** File description:
** init pages for the help menu
*/

#include <stddef.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "libmy.h"
#include "my_rpg.h"

page_t *get_page(char *path)
{
    page_t *page = check_malloc(sizeof(page_t));
    char **arr = NULL;
    FILE *stream = fopen(path, "r");

    if (!page || !stream)
        return NULL;
    *page = (page_t){NULL, NULL, NULL};
    for (char *line = NULL; (line = read_line(stream)); free(arr)) {
        arr = my_stoa(line, ':');
        if (my_arrlen(arr) == 2 && !my_strcmp("texts", arr[0]))
            page->texts = init_text_grid(arr + 1, stream);
        if (my_arrlen(arr) == 2 && !my_strcmp("images", arr[0]))
            page->images = init_image_grid(arr + 1, stream);
    }
    fclose(stream);
    return page;
}

page_t **init_pages(char **array)
{
    int nb = my_atoi(array[0]);
    page_t **pages = NULL;

    if (!(pages = check_malloc((nb + 1) * sizeof(page_t *))))
        return NULL;
    for (int i = 1; array[i]; i++)
        pages[i - 1] = get_page(array[i]);
    pages[nb] = NULL;
    return pages;
}
