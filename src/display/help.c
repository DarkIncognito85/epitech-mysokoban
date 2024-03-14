/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** help.c
*/
#include "my.h"

int display_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("file representing the warehouse map");
    my_putstr("containing ‘#’ for walls,\n");
    my_putstr("for the player, ‘X’ for boxes and ‘O’ for storage locations.");
    my_putchar('\n');
    return 0;
}
