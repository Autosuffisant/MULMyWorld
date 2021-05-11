/*
** EPITECH PROJECT, 2019
** put number in given base
** File description:
** put nbr base
*/
#include <unistd.h>
#include "../../include/my.h"

int my_putnbr_base(int nbr, char const *base)
{
    int base_size = my_strlen(base);

    if (nbr < 0) {
        nbr *= -nbr;
        my_putchar('-');
    }
    if (nbr / base_size == 0) {
        my_putchar(base[nbr % base_size]);
        return (0);
    }
    my_putnbr_base(nbr / base_size, base);
    my_putchar(base[(nbr % base_size)]);
    return (0);
}
