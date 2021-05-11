/*
** EPITECH PROJECT, 2019
** Task05
** File description:
** Return number from string
*/
#include <unistd.h>
#include "../../include/my.h"

int is_negative(char const *str, int is_neg)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '-') {
            is_neg *= -1;
        }
        i++;
    }
    if (is_neg == -1)
        my_putchar('-');
    return (is_neg);
}

int my_getnbr(char const *str)
{
    int nbr = 0;
    int is_neg = 1;

    is_neg = is_negative(str, is_neg);
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = (nbr * 10) + (str[i] - '0');
        }
        if ((str[i + 1] < '0' || str[i + 1] > '9') && \
            str[i] >= '0' && str[i] <= '9') {
            return (nbr);
        }
    }
    return (nbr);
}
