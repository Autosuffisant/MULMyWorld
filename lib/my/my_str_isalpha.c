/*
** EPITECH PROJECT, 2019
** Task12
** File description:
** return 1 if string only has alphabetical characters and 0 if not
*/
#include "../../include/my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (!(str[i] <= 'Z' && str[i] >= 'A')) {
            if (!(str[i] <= 'z' && str[i] >= 'a')) {
                return (0);
            }
        }
    }
    return (1);
}
