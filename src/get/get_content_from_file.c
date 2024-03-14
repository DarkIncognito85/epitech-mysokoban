/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** get_content_from_file.c
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *get_content_from_file(char *file)
{
    int fd = open(file, O_RDONLY);
    char *content;
    int size;
    struct stat buf;

    if (fd == -1){
        exit(84);
    }
    stat(file, &buf);
    size = buf.st_size;
    content = malloc((size + 1) * sizeof(char *));
    size = read(fd, content, size);
    content[size] = '\n';
    close(fd);
    return content;
}
