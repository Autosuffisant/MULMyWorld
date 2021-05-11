/*
** EPITECH PROJECT, 2019
** Task01
** File description:
** Swaps content of two integers given as parameter
*/
#include <unistd.h>
#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
