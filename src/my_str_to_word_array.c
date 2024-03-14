/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_str_to_word_array.c
*/

#include <stddef.h>
#include <stdlib.h>
char **my_str_to_word_array(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **tab = malloc(sizeof(char *) * 100);

    while (str[i] != '\0') {
        tab[j] = malloc(sizeof(char) * 100);
        while (str[i] != '\n' && str[i] != '\0') {
            tab[j][k] = str[i];
            i++;
            k++;
        }
        tab[j][k] = '\0';
        k = 0;
        j++;
        i++;
    }
    tab[j] = NULL;
    return (tab);
}
