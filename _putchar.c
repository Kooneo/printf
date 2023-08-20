#include <unistd.h>
#include "main.h"
/**
 * _putchar - Writes the character c to the standard output.
 * @c: The character to be printed.
 *
 * Return: On success 1.
 *         On error, -1 is returned and errno is set appropriately.
 */

int _putchar(int c)
{
    return (write(1, &c, 1));
}