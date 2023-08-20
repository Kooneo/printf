#include "main.h"
#include <stdarg.h>

/**
 * process_format - Handles a format specifier.
 * @fmt_ptr: Pointer to the current position in the format string.
 * @arguments: List of arguments.
 *
 * Returns: Number of characters processed.
 */

int process_format(const char **fmt_ptr, va_list arguments)
{
    int char_count = 0;
    int (*function)(va_list);

    (*fmt_ptr)++;

    if (**fmt_ptr == '\0')
    {
        _putchar(**fmt_ptr);
        return 1;
    }

    function = _spechandler(**fmt_ptr);

    if (function)
        char_count += function(arguments);
    else
    {
        _putchar(**fmt_ptr);
        char_count++;
    }

    return char_count;
}

/**
 * _printf - Print formatted output with custom formatting.
 * @format: Format string containing placeholders.
 *
 * Returns: Number of characters printed.
 */

int _printf(const char *format, ...)
{
    va_list arguments;
    int char_count = 0;

    if (!format || (format[0] == '%' &&
                 (!format[1] || (format[1] == ' ' &&
                              !format[2]))))
        return -1;

    va_start(arguments, format);

    while (*format)
    {
        if (*format == '%')
        {
            char_count += process_format(&format, arguments);
        }
        else
        {
            _putchar(*format);
            char_count++;
        }

        format++;
    }

    va_end(arguments);
    return char_count;
}