#include "main.h"

/**
 * get_precision - Calculates the precision
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int cur = *i + 1;
	int precision = -1;

	if (format[cur] != '.')
		return (precision);

	precision = 0;

	for (cur += 1; format[cur] != '\0'; cur++)
	{
		if (is_digit(format[cur]))
		{
			precision *= 10;
			precision += format[cur] - '0';
		}
		else if (format[cur] == '*')
		{
			cur++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = cur - 1;

	return (precision);
}
