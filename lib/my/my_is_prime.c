/*
** EPITECH PROJECT, 2019
** Task06
** File description:
** Check for prime number
*/
#include <unistd.h>
#include "../../include/my.h"

int my_is_prime(int nb)
{
    if (nb <= 1)
        return (0);
    for (int i = 2; i < nb; i++) {
        if (nb == (nb / i * i)) {
            return (0);
        }
    }
    return (1);
}
