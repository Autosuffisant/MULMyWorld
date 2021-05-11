/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../include/my.h"
#include "../../include/my_printf.h"

void handle_flag(va_list ap, char c)
{
    for (int i = 0; flags_array[i].flag != 0; i++)
        if (flags_array[i].flag == c)
            flags_array[i].fptr(ap);
}

int my_printf(char const *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            handle_flag(ap, format[i + 1]);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(ap);
    return (0);
}
