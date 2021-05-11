/*
** EPITECH PROJECT, 2019
** Task10
** File description:
** Capitalize first letter of each word in string
*/

#include "../../include/my.h"

char *put_caps(char *str, int i)
{
    int b = i - 1;
    if (!(str[b] <= '9' && str[b] >= '0') && !(str[b] <= 'z' && str[b] >= 97)) {
        if (!(str[b] <= 'Z' && str[b] >= 'A')) {
            str[i] -= 32;
        }
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 'Z' && str[i] >= 'A') {
            str[i] += 32;
        }
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            put_caps(str, i);
        }
    }
    return (str);
}
