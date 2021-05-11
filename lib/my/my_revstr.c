/*
** EPITECH PROJECT, 2019
** Task03
** File description:
** Reverse a string
*/
#include "../../include/my.h"

int my_swap_str(char *str1, char *str2)
{
    char tmp;
    tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
    return (0);
}

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

char *my_revstr(char *str)
{
    int length;
    length = my_strlen(str);
    int i = 0;

    while (i < length / 2) {
        my_swap_str(str + i, str + (length - i - 1));
        i++;
    }
    return (str);
}
