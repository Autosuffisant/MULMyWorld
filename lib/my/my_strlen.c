/*
** EPITECH PROJECT, 2019
** Task03
** File description:
** Returns size of string
*/
#include <unistd.h>
#include "../../include/my.h"

int my_strlen(char const *str)
{
    int strSize = 0;

    while (*str != '\0')
    {
        str++;
        strSize++;
    }
    return (strSize);
}
