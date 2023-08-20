#include "main.h"
#include "_print_char.c"

/**
 * _spechandler - Get the corresponding custom function for a specifier.
 * @specifier: Specifier to be matched.
 *
 * Return: If matched, returns a pointer to the function, otherwise returns NULL.
 */

int (*_spechandler(char specifier))(va_list)
{
    int i;
    custom_spec custom_specifiers[] = {
        {'c', _print_char},
        {'s', _print_string},
        {'%', _print_percent},
        {'\0', NULL}
    };

    for (i = 0; custom_specifiers[i].function; i++)
    {
        if (custom_specifiers[i].specifier == specifier)
            return custom_specifiers[i].function;
    }

    return NULL;
}
