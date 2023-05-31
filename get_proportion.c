#include "main.h"

/**
 * get_proportion - Calculates the proportion to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_proportion(const char *format, int *i)
{
	int curr_i = *i + 1;
	int proportion = 0;

	if (format[curr_i] == 'l')
		proportion = S_LONG;
	
	else if (format[curr_i] == 'h')
		proportion = S_SHORT;

	if (proportion == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (proportion);
}
