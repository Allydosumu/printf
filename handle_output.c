#include "main.h"
/**
 * handle_output- ouput of an argument based on its type
 * @mat: Formatted string in which the output of the arguments are displayed
 * @list: List of arguments to be printed.
 * @index: index.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_output(const char *mat, int *index, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	mat_t mat_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; mat_types[i].mat != '\0'; i++)
		if (mat[*index] == mat_types[i].mat)
			return (mat_types[i].fn(list, buffer, flags, width, precision, size));

	if (mat_types[i].mat == '\0')
	{
		if (mat[*index] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (mat[*index - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (mat[*index] != ' ' && mat[*index] != '%')
				--(*index);
			if (mat[*index] == ' ')
				--(*index);
			return (1);
		}
		unknow_len += write(1, &mat[*index], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
