/*
** EPITECH PROJECT, 2019
** functions
** File description:
** printf
*/

#include "../../include/my.h"
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void va_putnbr_octal(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01234567");
}

void va_unsigned_int(va_list ap)
{
    my_putnbr_base(va_arg(ap, long), "0123456789");
}

void va_pointer(va_list ap)
{
    my_putstr("0x");
    my_putnbr_base(va_arg(ap, int), "0123456789abcdef");
}

void va_mod(va_list ap)
{
    my_putchar('%');
}

void va_putstr_octal(va_list ap)
{
    char *str = va_arg(ap, char *);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            if (str[i] > 100)
                my_putstr("00");
            if (str[i] > 10 && str[i] < 100)
                my_putchar('0');
            my_putnbr_base(str[i], "01234567");
        }
    }
}
