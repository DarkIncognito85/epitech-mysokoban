/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** player.c
*/

#include "my.h"
int check_x(int y, int x, char **tab, game_t *game)
{
    location_t *player = game->player;
    int row = y + player->y;
    int col = x + player->x;

    if (tab[row][col] == NULL) {
        return 0;
    }
    if (row == 0 || game->heigth == row){
        return 0;
    }
    if (tab[row][col] == 'X') {
        if (tab[row + y * 1][col + x * 1] == '#'){
            return 0;
        }
        tab[row + y][col + x] = 'X';
    }
    return 1;
}

int check_o(char **tab, int i, int j, int count_o)
{
    if (tab[i][j] == 'O') {
        count_o++;
    }
    return count_o;
}

int move_player(int y, int x, char **tab, game_t *game)
{
    location_t *player = game->player;
    int row = y + player->y;
    int col = x + player->x;
    char replace;

    if (check_x(y, x, tab, game) == 0) {
        return 0;
    }
    if (tab[row][col] == '#') {
        return 0;
    }
    replace = game->initial[player->y][player->x];
    if (replace != 'O'){
        replace = ' ';
    }
    tab[player->y][player->x] = replace;
    player->x = col;
    player->y = row;
    tab[row][col] = 'P';
    return 0;
}

void check_player(char **tab, int x, int y, location_t *player)
{
    if (tab[y][x] == 'P') {
        player->x = x;
        player->y = y;
    }
}

location_t *get_player_location(int count, char **tab)
{
    location_t *player = malloc(sizeof(location_t));

    player->x = 0;
    player->y = 0;
    for (int i = 1; i <= count; i++) {
        for (int j = 1; j <= my_strlen(tab[i]) - 2; j++) {
            check_player(tab, j, i, player);
        }
    }
    return player;
}
