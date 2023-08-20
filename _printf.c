#include "main.h"

/**
 * _printf - Print formatted output to stdout.
 *
 * Description: This function implements a simplified
 * version of the printf function that
 * supports the following conversion specifiers: %c, %s, and %%.
 *
 * @format: format The format string containing directives and text to print.
 * @param ... Variable arguments corresponding to the format specifiers.
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	int count;
	va_list args;

	va_start(args, format);
	count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				break;
			}

			if (*format == 'c')
			{
			print_char(args, count);
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				while (*s != '\0')
				{
					write(1, s, 1);
					s++;
					count++;
				}
			}
	else if (*format == '%')
	{
	char percent_char = '%';

	write(1, &percent_char, 1);
	count++;
	}
	}
	else
	{
	write(1, format, 1);
	count++;
	}
	format++;
	}

	va_end(args);
	return (count);
}
