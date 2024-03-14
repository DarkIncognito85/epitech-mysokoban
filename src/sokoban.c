/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** sokoban.c
*/

#include <ncurses.h>
#include <string.h>
#include "my.h"

static int check_is_win(char *str, int x, int count, char *initial)
{
    if (str[x] == 'X' && initial[x] == 'O') {
        count--;
    }
    return count;
}

int is_win(char **tab, game_t *game)
{
    int count = game->count;

    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            count = check_is_win(tab[i], j, count, game->initial[i]);
        }
    }
    if (count == 0) {
        noecho();
        endwin();
        return 1;
    }
    return 0;
}

game_t *make_sokoban(char *content)
{
    game_t *game = malloc(sizeof(game_t));
    int count_o = 0;
    int count_x = 0;

    count_o = get_count_o(content);
    count_x = get_count_x(content);
    if (count_o != count_x){
        exit(84);
    }
    return game;
}

int reset_game(char **tab, game_t *game)
{
    location_t *loc;

    for (int i = 0; i < game->heigth; i++) {
        tab[i] = game->initial[i];
    }
    loc = get_player_location(game->heigth, tab);
    game->player = loc;
    game->initial = my_strdup(game->initial, game->heigth);
    return 0;
}

int fill_sokoban(game_t *game_instance, char *content, char **tab)
{
    game_instance->heigth = get_count_tab(content);
    game_instance->width = get_max_width(tab);
    game_instance->len = my_strlen(content);
    game_instance->initial = my_strdup(tab, game_instance->heigth);
    game_instance->count = get_count_o(content);
    return 0;
}

static int check_valid_char(char *content)
{
    for (int i = 0; i <= my_strlen(content); i++) {
        if (content[i] != '#' && content[i] != 'O' &&
            content[i] != 'X' && content[i] != 'P' && content[i] != ' ' &&
            content[i] != '\n' && content[i] != '\0'
        ) {
            exit(84);
        }
    }
    return 0;
}

int sokoban(char *filename)
{
    game_t *game_instance;
    char *content;
    char **tab;

    content = get_content_from_file(filename);
    check_valid_char(content);
    game_instance = make_sokoban(content);
    tab = my_str_to_word_array(content);
    fill_sokoban(game_instance, content, tab);
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    render(tab, game_instance);
    noecho();
    endwin();
    return 0;
}
