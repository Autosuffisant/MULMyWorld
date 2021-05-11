/*
** EPITECH PROJECT, 2019
** Memset
** File description:
** my_memset.c
*/

#include <stdlib.h>

void *my_memset(void *dest, int data, size_t n)
{
    char *ptr = dest;

    for (; n > 0; n--)
        *ptr++ = data;
    return (dest);
}