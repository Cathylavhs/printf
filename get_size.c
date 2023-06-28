#include "main.h"

/**
 * get_size - Calculates the size to cast
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int cur = *i + 1;
	int size = 0;

	if (format[cur] == 'l')
		size = S_LONG;
	else if (format[cur] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = cur - 1;
	else
		*i = cur;

	return (size);
}
