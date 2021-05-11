/*
** EPITECH PROJECT, 2019
** Task02
** File description:
** Write a string
*/
#include <unistd.h>
#include "../../include/my.h"

int my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (0);
}
