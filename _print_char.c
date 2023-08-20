#include "main.h"

/**
 * _print_char - Print individual characters.
 * @arguments: List of arguments.
 *
 * Return: On success, returns the number of characters printed.
 */

int _print_char(va_list arguments)
{
    char c = va_arg(arguments, int);

    _putchar(c);
    return 1;
}