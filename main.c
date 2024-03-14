/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** main.c
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "my.h"

int main(int argc, char **argv)
{
    struct stat buf;

    if (argc != 2){
        exit(84);
    }
    if (argv[1][0] == '-'){
        return display_help();
    }
    if (stat(argv[1], &buf) < 0){
        exit(84);
    }
    return sokoban(argv[1]);
}
