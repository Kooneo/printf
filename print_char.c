#include "main.h"
#include <stdio.h>

/**
 * print_char - write the character c
 * @args: input char
 * @count: counter
 * Return: counter
 */
int print_char(va_list args, int count)
{
	int c = va_arg(args, int);

	write(1, &c, 1);

	return (count++);
}
