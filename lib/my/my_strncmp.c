/*
** EPITECH PROJECT, 2019
** Task07
** File description:
** Reproduce behavior of strncmp
*/
#include "../../include/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (n < 0)
        n *= -1;
    while ((s1[i] && s2[i] && s1[i] == s2[i]) && i < n)
        i++;
    return (s1[i] - s2[i]);
}
