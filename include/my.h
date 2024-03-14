/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my.h
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdarg.h>
#include <dirent.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>
#ifndef MY_H
    #define MY_H

typedef enum direction_s {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    DEFAULT,
} direction_t;
typedef struct location_s {
    int x;
    int y;
} location_t;

typedef struct game_s {
    location_t *player;
    char **initial;
    int count;
    int heigth;
    int width;
    int len;
} game_t;

int display_help(void);
int my_strlen(const char *str);
char *get_content_from_file(char *file);
char **my_str_to_word_array(char *str);
int my_putstr(const char *str);
int my_put_nbr(int nb);
game_t *make_sokoban(char *content);
int is_win(char **tab, game_t *game);
int my_putchar(char str);
int render(char **tab, game_t *game);
// get_count
int get_count_tab(char *str);
int get_count_x(char *str);
int get_count_o(char *str);
int get_max_width(char **tab);

// sokoban.c
int sokoban(char *filename);
int reset_game(char **tabs, game_t *game);
// player.c
int move_player(int y, int x, char **tab, game_t *game);
location_t *get_player_location(int count, char **tab);
void check_player(char **tab, int x, int y, location_t *player);
int check_x(int y, int x, char **tab, game_t *game);
int check_o(char **tab, int i, int j, int count_o);
// border.c
int check_valid_border(char **tab, int i);
//my_strdup.c
char *my_strcpy(char *dest, char *src);
char **my_strdup(char **src, int count);
//free_all.c
void free_all(game_t *game, char **tab);

#endif /* !MY_H */
