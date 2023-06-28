#include "main.h"

/**
 * get_flags - Calculates the active flags
 * @format: Formatted string in which to print the arguments
 * @i: take  parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int c, cur;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur = *i + 1; format[cur] != '\0'; cur++)
	{
		for (c = 0; FLAGS_CH[c] != '\0'; c++)
			if (format[cur] == FLAGS_CH[c])
			{
				flags |= FLAGS_ARR[c];
				break;
			}

		if (FLAGS_CH[c] == 0)
			break;
	}

	*i = cur - 1;

	return (flags);
}

