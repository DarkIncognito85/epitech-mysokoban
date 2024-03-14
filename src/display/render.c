/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** render.c
*/
#include <ncurses.h>
#include <string.h>
#include "my.h"

void print_lines(char **tab)
{
    clear();
    for (int i = 0; tab[i] != NULL; i++){
        printw(tab[i]);
        printw("\n");
        refresh();
    }
}

int moved_event(char **tab, game_t *game)
{
    int ch = getch();

    switch (ch) {
        case KEY_UP:
            move_player(-1, 0, tab, game);
            break;
        case KEY_DOWN:
            move_player(1, 0, tab, game);
            break;
        case KEY_LEFT:
            move_player(0, -1, tab, game);
            break;
        case KEY_RIGHT:
            move_player(0, 1, tab, game);
            break;
        case ' ':
            reset_game(tab, game);
    }
    return 0;
}

int render(char **tab, game_t *game)
{
    location_t *loc = get_player_location(game->heigth, tab);

    if (loc->x == 0 && loc->y == 0){
        exit(84);
    }
    game->player = loc;
    while (1) {
        print_lines(tab);
        if (is_win(tab, game) == 1){
            break;
        }
        moved_event(tab, game);
    }
    free_all(game, tab);
    return 0;
}
