/*
** EPITECH PROJECT, 2022
** str_to_word_array
** File description:
** SE
*/

#include <stdlib.h>
#include "libmy.h"

char **my_stoa(char *str, char sep)
{
    int words = count_chars(str, sep) + 1;
    char **word_array = my_arrmalloc(0, words);

    for (int i = 0; i < words; i++) {
        word_array[i] = str;
        while (*str != '\0' && *str != sep)
            str++;
        *(str++) = '\0';
    }
    return word_array;
}
