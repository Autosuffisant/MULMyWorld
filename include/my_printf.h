/*
** EPITECH PROJECT, 2019
** my_printf_array_function_pointers
** File description:
** include
*/

#ifndef H_PRINTF
#define H_PRINTF

#include "my.h"
#include <stdarg.h>

void va_putchar(va_list ap);
void va_putstr(va_list ap);
void va_putnbr_base(va_list ap);
void va_putnbr_base_bin(va_list ap);
void va_putnbr_hexa(va_list ap);
void va_putnbr_octal(va_list ap);
void va_unsigned_int(va_list ap);
void va_pointer(va_list ap);
void va_mod(va_list ap);
void va_putstr_octal(va_list ap);

typedef struct flags_s {
    char flag;
    void (*fptr)(va_list);
} flags_t;

const flags_t flags_array[] = {
    { 'c', va_putchar},
    { 's', va_putstr},
    { 'd', va_putnbr_base},
    { 'i', va_putnbr_base},
    { 'b', va_putnbr_base_bin},
    { 'o', va_putnbr_octal },
    { 'S', va_putstr_octal },
    { 'u', va_unsigned_int },
    { 'x', va_putnbr_hexa },
    { 'X', va_putnbr_hexa },
    { 'p', va_pointer },
    { '%', va_mod },
    {0}
};

#endif
