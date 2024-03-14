/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** get_count_tab.c
*/

int get_count_tab(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n'){
            count++;
        }
    }
    return count - 1;
}
