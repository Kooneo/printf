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
            else if (*format == 'u') {
                unsigned int num = va_arg(args, unsigned int);
                unsigned int temp = num;
                int i, digit;
                int digit_count = 0;

                do {
                    temp /= 10;
                    digit_count++;
                } while (temp != 0);

                while (digit_count > 0) {
                    temp = num;
                    for ( i = 1; i < digit_count; i++) {
                        temp /= 10;
                    }
                    digit = temp % 10;
                    putchar('0' + digit);
                    count++;
                    digit_count--;
                }
            } 
            else if (*format == 'd' || *format == 'i') {
                int num = va_arg(args, int);
                int temp = num;
                int digit_count = 0;

                if (num < 0) {
                    num = -num;
                    putchar('-');
                    count++;
                }

                do {
                    temp /= 10;
                    digit_count++;
                } while (temp != 0);

                while (digit_count > 0) {
                    int i, digit;
                    temp = num;

                    for (i = 1; i < digit_count; i++) {
                        temp /= 10;
                    }
                    digit = temp % 10;
                    putchar('0' + digit);
                    count++;
                    digit_count--;
                }
            }
            else if (*format == 'x' || *format == 'X') {
                int i;
                int num = va_arg(args, int);
                char hex_digits[] = "0123456789ABCDEF";
                int max_digits = snprintf(NULL, 0, "%X", num);
                for (i = max_digits - 1; i >= 0; i--) {
                    int digit = (num >> (i * 4)) & 0xF;
                    putchar(hex_digits[digit]);
                    count++;
                }
            }
            else if (*format == 'o') {
                unsigned int num = va_arg(args, unsigned int);
                unsigned int temp = num;
                int digit_count = 0;
                int i, digit;
                
                do {
                    temp /= 8;
                    digit_count++;
                } while (temp != 0);
                while (digit_count > 0) {
                    temp = num;
                    for (i = 1; i < digit_count; i++) {
                        temp /= 8;
                    }
                    digit = temp % 8;
                    putchar('0' + digit);
                    count++;
                    digit_count--;
                }
            }
            else if (*format == 'p') {
                void *ptr = va_arg(args, void *);
                uintptr_t address = (uintptr_t)ptr;
                printf("0x%lX", address);
                count += snprintf(NULL, 0, "0x%lX", address);
            }
            else {
                putchar('%');
                putchar(*format);
                count++;
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
