/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** my_strdup.c
*/
#include <stdlib.h>
#include "my.h"
char *my_strcpy(char *dest, char *src)
{
    int strlen = my_strlen(src);

    for (int i = 0; i < strlen; i++) {
        dest[i] = src[i];
    }
    dest[strlen] = '\0';
    return dest;
}

char **my_strdup(char **src, int count)
{
    char **dest = malloc(sizeof(char *) * count);

    for (int i = 0; i < count; i++) {
        dest[i] = malloc(sizeof(char) * my_strlen(src[i]));
        my_strcpy(dest[i], src[i]);
    }
    return dest;
}
