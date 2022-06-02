/*
** EPITECH PROJECT, 2022
** quest
** File description:
** update quest
*/

#include "my_rpg.h"
#include "structs.h"
#include "libmy.h"
#include <SFML/Graphics.h>
#include <SFML/Window.h>

void quest_change(quest_t *quest, int current_map)
{
    if (quest->map == current_map)
        quest->completed = sfTrue;
}

void update_quest(quest_t **quests, int current_map)
{
    if (!quests)
        return;
    for (int i = 0; quests[i]; i++) {
        if (!my_strcmp(quests[i]->type, "change") && quests[i]->completed == sfFalse
        && quests[i]->active == sfTrue)
            quest_change(quests[i], current_map);
        if (quests[i]->completed == sfTrue && quests[i]->active == sfTrue) {
            quests[i]->active = sfFalse;
            my_printf("Quest %s completed\n", quests[i]->name);
        }
    }
}
