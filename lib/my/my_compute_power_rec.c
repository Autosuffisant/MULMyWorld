/*
** EPITECH PROJECT, 2019
** Task04
** File description:
** Compute power recursively
*/
#include <unistd.h>
#include "../../include/my.h"

int my_compute_power_rec(int nb, int p)
{
    long result = 0;

    if (p < 0)
        return (0);
    if (p == 0) {
        return (1);
    } else {
        result = (nb * my_compute_power_rec(nb, p - 1));
        if (result > 2147483647 || result < -2147483648)
            return (0);
        return (result);
    }
}
