/*
** EPITECH PROJECT, 2019
** Task04
** File description:
** Displays either N or P if the interger passed
** as parameter is Negative or Positive
*/
#include <unistd.h>
#include "../../include/my.h"

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}
