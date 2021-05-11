/*
** EPITECH PROJECT, 2019
** Task09
** File description:
** Put a string in lowercase
*/
#include "../../include/my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] <= 90 && str[i] >= 65) {
            str[i] += 32;
        }
    }
    return (str);
}

