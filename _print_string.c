#include "main.h"

/**
 * _print_string - Print strings.
 * @arguments: List of arguments.
 *
 * Return: The number of characters printed.
 */

int _print_string(va_list arguments)
{
    char *str = va_arg(arguments, char*);
    int char_count = 0;

    if (!str)
    {
        str = "(null)";
    }

    while (*str)
    {
        _putchar(*str++);
        char_count++;
    }

    return char_count;
}