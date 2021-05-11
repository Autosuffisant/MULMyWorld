/*
** EPITECH PROJECT, 2019
** Task07
** File description:
** Returns smallest prime number that is greater than
** or equal to the number given as a parameter
*/
#include <unistd.h>
#include "../../include/my.h"

int my_find_prime_sup(int nb)
{
    for (nb; !my_is_prime(nb); nb++) {
        if (nb >= 2147483646)
            return (0);
    }
    return (nb);
}
