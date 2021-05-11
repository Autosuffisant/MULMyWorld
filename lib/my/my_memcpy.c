/*
** EPITECH PROJECT, 2019
** Memcpy
** File description:
** my_memcpy.c
*/

#include <stdlib.h>

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *ptr = dest;
    const char *tmp = src;

    for (; n > 0; n--)
        *ptr++ = *tmp++;
    return (dest);
}