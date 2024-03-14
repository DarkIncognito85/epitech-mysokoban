/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** display the number you put as a parameter
*/

#include <unistd.h>

static void modulo_part(int *modulo, int *nb)
{
    *modulo = *nb % 10;
    *nb = (*nb - *modulo) / 10;
}

int my_put_nbr(int nb)
{
    int modulo;
    int i = 0;

    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return (0);
    } else if (nb < 0 && nb != -2147483648) {
        nb = -nb;
        write(1, "-", 1);
    }
    if (nb >= 10) {
        modulo_part(&modulo, &nb);
        my_put_nbr(nb);
        i = 48 + modulo;
        write(1, &i, 1);
    } else {
        i = 48 + nb % 10;
        write(1, &i, 1);
    }
    return 0;
}
