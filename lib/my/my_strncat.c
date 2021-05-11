/*
** EPITECH PROJECT, 2019
** Task03
** File description:
** Copy the behavior of strncat
*/
#include "../../include/my.h"

char *my_strncat(char *dest, const char *src, int nb)
{
    int dest_len = my_strlen(dest);
    int i;

    for (i = 0 ; i < nb && src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}
