#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <limits.h>


int _putchar(int c);
int process_custom_format(const char **format_ptr, va_list arguments);

int _print_char(va_list arguments);
int _print_string(va_list arguments);
int _print_percent(va_list arguments);
int _printf(const char *format, ...);
int (*_spechandler(char specifier))(va_list);

/**
 * custom_specifier - Custom specifier structure.
 * @specifier: Specifier character.
 * @function: Function pointer to a function that handles the specifier.
 */

typedef struct custom_specifier
{
    char specifier;
    int (*function)(va_list arguments);
} custom_spec;

#endif