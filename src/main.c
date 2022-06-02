/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** main
*/

#include "libmy.h"
#include "my_rpg.h"

int main(int ac, char **av)
{
    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return usage();
    if (ac != 1)
        return 84;
    return my_rpg();
}
