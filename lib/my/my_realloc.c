/*
** EPITECH PROJECT, 2019
** Realloc
** File description:
** my_realloc.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../include/my.h"

void *my_realloc(void *ptr, size_t old_size, size_t new_size)
{
    void *tmp = malloc(new_size);

    if (ptr && tmp) {
        if (old_size < new_size)
            my_memcpy(tmp, ptr, old_size);
        else
            my_memcpy(tmp, ptr, new_size);
    }
    if (tmp || (new_size == 0)) {
        free(ptr);
    }
    return (tmp);
}