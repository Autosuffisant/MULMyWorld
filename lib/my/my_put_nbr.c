/*
** EPITECH PROJECT, 2019
** Task07
** File description:
** Displays number given as parameter
*/
#include <unistd.h>
#include "../../include/my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * (-1));
    } else if ((nb <= 9) && (nb >= 0)) {
        my_putchar(nb+'0');
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return (0);
}
