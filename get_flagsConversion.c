#include "main.h"

/**
 *get_flagsConversion - Calculates active flags
 *@format: print the arguments of the formatted string
 *@i: take a parameter
 *Return: Flags.
 */

int get_flagsConversion(const char *format, int *i)
{
	/* - + 0 # '' */
	int b, curr_i;
	int flags = 0;
	const char FLAG_CH[] = {'_', '+', '0', '#', ' ', '\0'};
	const int FLAG_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CH[b] != '\0'; b++)
			if (format[curr_i] == FLAGS_CH[b])
			{
				flags |= FLAGS_ARR[b];
				break;
			}
		if (FLAGS_CH[b] == 0)
			break;
	}
	*i = curr_i - 1;

	return (flags);
}