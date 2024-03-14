/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** get_count.c
*/
#include "my.h"

int get_count_o(char *str)
{
    int count = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == 'O'){
            count++;
        }
    }
    return count;
}

int get_count_x(char *str)
{
    int count = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == 'X'){
            count++;
        }
    }
    return count;
}

int get_max_width(char **tab)
{
    int i = 0;
    int max = 0;

    while (tab[i] != NULL) {
        if (my_strlen(tab[i]) > max)
            max = my_strlen(tab[i]);
        i++;
    }
    return max;
}
