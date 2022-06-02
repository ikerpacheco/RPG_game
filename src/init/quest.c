/*
** EPITECH PROJECT, 2022
** quest
** File description:
** init quest
*/

#include "my_rpg.h"
#include "structs.h"
#include "libmy.h"

quest_t *init_quest(char **arr)
{
    quest_t *quest = check_malloc(sizeof(quest_t));

    if (!quest)
        return NULL;
    *quest = (quest_t){0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0};
    quest->completed = sfFalse;
    quest->active = sfFalse;
    if (*(arr[0]) && *(arr[1]) && *(arr[2])) {
        quest->id = my_atoi(arr[0]);
        quest->type = arr[1];
        quest->name = arr[2];
    }
    if (*(arr[3]))
        quest->map = my_atoi(arr[3]);
    if (*(arr[4]) && *(arr[5])) {
        quest->id_actor = my_atoi(arr[4]);
        quest->quantity = my_atoi(arr[5]);
    }
    if (*(arr[6]) && *(arr[7])) {
        quest->coins = my_atoi(arr[6]);
        quest->item = my_atoi(arr[7]);
    }
    if (*(arr[8]))
        quest->author = my_atoi(arr[8]);
    return quest;
}

quest_t **init_quest_grid(char **arr, FILE *stream)
{
    int nb = my_atoi(arr[0]);
    quest_t **quests = check_malloc(sizeof(quest_t *) * nb + 1);
    char **array = NULL;

    if (!quests)
        return NULL;
    for (int i = 0; i < nb; i++) {
        array = my_stoa(read_line(stream), ':');
        if (my_arrlen(array) == 10 && !my_strcmp(array[0], "quest"))
            quests[i] = init_quest(array + 1);
        free(array);
    }
    quests[nb] = NULL;
    return quests;
}
