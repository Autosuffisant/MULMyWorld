/*
** EPITECH PROJECT, 2019
** Task05
** File description:
** Reproduce behavior of strstr function
*/
#include "../../include/my.h"

char *my_strstr(char *str, char const *to_find)
{
    char *a = str;
    char const *b = to_find;

    while (*str)
    {
        while (*str && *b && *str == *b)
        {
            str++;
            b++;
        }
        if (!*b) {
            return (a);
        }
        str = a + 1;
    }
    return (0);
}
