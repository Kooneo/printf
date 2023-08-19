#include "main.h"

/**
 * Print formatted output to stdout.
 *
 * This function implements a simplified version of the printf function that
 * supports the following conversion specifiers: %c, %s, and %%.
 *
 * @param format The format string containing directives and text to print.
 * @param ... Variable arguments corresponding to the format specifiers.
 * @return The number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0; // To keep track of the number of characters printed
    
    while (*format != '\0') {
        if (*format == '%') {
            format++; // Move past '%'
            if (*format == '\0') {
                break; // Handle cases like "%%" at the end of the format string
            }
            if (*format == 'c') {
                // Print a character
                int c = va_arg(args, int);
                putchar(c);
                count++;
            } else if (*format == 's') {
                // Print a string
                char *s = va_arg(args, char *);
                while (*s != '\0') {
                    putchar(*s);
                    s++;
                    count++;
                }
            } else if (*format == '%') {
                // Print a literal '%'
                putchar('%');
                count++;
            } else {
                // Unsupported conversion specifier
                // You can add error handling here if needed
            }
        } else {
            // Print regular characters
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}
