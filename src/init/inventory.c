/*
** EPITECH PROJECT, 2022
** slots
** File description:
** slots
*/

#include <SFML/Graphics.h>
#include "libmy.h"
#include "my_rpg.h"

slot_t *create_slot(int pos_x, int pos_y, char *path, char *path2)
{
    slot_t *slot = NULL;
    sfVector2f size = {42, 42};

    if (!(slot = check_malloc(sizeof(slot_t))))
        return NULL;
    *slot = (slot_t){NULL, NULL, {0, 0}, NULL, NULL, 0};
    if ((slot->render = check_malloc(sizeof(render_t *) * 3))) {
        slot->render[0] = init_render(path);
        slot->render[1] = init_render(path2);
        slot->render[2] = NULL;
    }
    slot->pos = init_pos((sfVector2f){17 + pos_x, 107 + pos_y});
    slot->rect = init_rect(slot->pos->pos, size);
    return slot;
}

slot_t **init_slots(char **arr)
{
    slot_t **slots = NULL;
    char *slot1 = arr[0];
    char *test = arr[1];

    if (!(slots = check_malloc(41 * sizeof(slot_t *))))
        return NULL;
    for (int id = 0; id < 35; id++)
        slots[id] = create_slot(43 * (id % 7), 42 * (id / 7), slot1, test);
    slots[35] = create_slot(930, 0, "assets/inventory/s_sword.png", slot1);
    slots[36] = create_slot(930, 125, "assets/inventory/s_helmet.png", slot1);
    slots[37] = create_slot(930, 250, "assets/inventory/s_armor.png", slot1);
    slots[38] = create_slot(930, 375, "assets/inventory/s_gloves.png", slot1);
    slots[39] = create_slot(930, 500, "assets/inventory/s_boots.png", slot1);
    slots[40] = NULL;
    return slots;
}

inventory_t *init_inventory(char *path)
{
    FILE *fp = fopen(path, "r");
    inventory_t *inventory = check_malloc(sizeof(inventory_t));
    char **arr = NULL;

    if (!inventory || !fp)
        return NULL;
    *inventory = (inventory_t){NULL, {0, 0}, NULL, NULL, 0, 0, 0};
    for (char *line = NULL; (line = read_line(fp)); free(arr)) {
        arr = my_stoa(line, ':');
        if (my_arrlen(arr) == 4 && !my_strcmp(arr[0], "inventory")) {
            inventory->render = init_render(arr[1]);
            inventory->offset = (sfVector2f){my_atof(arr[2]), my_atof(arr[3])};
            inventory->pos = init_pos(inventory->offset);
        }
        if (my_arrlen(arr) == 3 && !my_strcmp(arr[0], "slots"))
            inventory->slots = init_slots(arr + 1);
    }
    fclose(fp);
    return inventory;
}
