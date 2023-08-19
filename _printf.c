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
    int count;
    va_list args;
    va_start(args, format);

    
    
    count = 0;
    
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == '\0') {
                break;
            }
            if (*format == 'c') {
                int c = va_arg(args, int);
                putchar(c);
                count++;
            } else if (*format == 's' ) {
                char *s = va_arg(args, char *);
                while (*s != '\0') {
                    putchar(*s);
                    s++;
                    count++;
                }
            } else if (*format == '%') {
                putchar('%');
                count++;
            }
            else if (*format == 'r') {
                putchar('%');
                putchar(*format);
                count++;
            }
            else {
                
            }
        } else {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}
