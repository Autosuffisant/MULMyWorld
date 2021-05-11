/*
** EPITECH PROJECT, 2019
** Task05
** File description:
** Calculate square root of given number
*/
#include <unistd.h>
#include "../../include/my.h"

int my_compute_square_root(int nb)
{
    int i = 1;
    int j = 1;

    while (i <= nb) {
        j = i * i;
        if (nb == j)
            return (i);
        i++;
    }
    return (0);
}
