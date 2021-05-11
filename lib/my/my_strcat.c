/*
** EPITECH PROJECT, 2019
** Task02
** File description:
** Copy behavior of strcat
*/
#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    my_strcpy(dest + my_strlen(dest), src);
    return (dest);
}
