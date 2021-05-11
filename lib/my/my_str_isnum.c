/*
** EPITECH PROJECT, 2019
** Task13
** File description:
** Returns 1 if string is made only of numbers and 0 otherwise
*/
#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] <= '9' && str[i] >= '0'))
            return (0);
    }
    return (1);
}
