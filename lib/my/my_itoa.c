/*
** EPITECH PROJECT, 2019
** itoa
** File description:
** my_itoa.c
*/

char *my_itoa(int value)
{
    static char buf[21];
    char *tmp = buf + 20;

    do {
        *--tmp = '0' + (value % 10);
        value /= 10;
    } while (value != 0);
    return (tmp);
}