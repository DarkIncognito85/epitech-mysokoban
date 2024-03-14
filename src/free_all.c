/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** free_all.c
*/
#include "my.h"
void free_all(game_t *game, char **tab)
{
    for (int i = 1; i < game->heigth; i++) {
        free(tab[i]);
        free(game->initial[i]);
    }
    free(tab);
    free(game->initial);
}
