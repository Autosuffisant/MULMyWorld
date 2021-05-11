/*
** EPITECH PROJECT, 2019
** Printf functions
** File description:
** modified to have easier use
*/

#include "../../include/my.h"
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void va_putchar(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void va_putstr(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void va_putnbr_base(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "0123456789");
}

void va_putnbr_base_bin(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "01");
}

void va_putnbr_hexa(va_list ap)
{
    my_putnbr_base(va_arg(ap, int), "0123456789ABCDEF");
}
