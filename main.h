#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x)(void)(x)
#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int handle_output(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* FLAG */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct mat - Struct operator
 *
 * @mat: The mat.
 * @fn: The associated function
 */
struct mat
{
	char mat;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct mat mat_t - Struct operator
 * @mat: The format used
 * @mat_t: The associated function
 */
typedef struct mat mat_t;

/* FUNCTIONS */
/* These functions are to print chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* These functions are to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non-printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flagsConversion(const char *format, int *i);
int get_span(const char *format, int *i, va_list list);
int get_accuracy(const char *format, int *i, va_list list);
int get_proportion(const char *format, int *i);

/* Function to print string in reverse */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print a string in rot 13 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int index, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int index, char bff[], int flags, int width, int precision,
	int length, char stretch, char extra_c);
int write_pointer(char buffer[], int index, int length,
	int width, int flags, char stretch, char extra_c, int stretch_start);

int write_unsgnd(int is_negative, int index, char buffer[],
	int flags, int width, int precision, int size);

/* UTILITY */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_unsgnd(unsigned long int num, int size);
long int convert_size_number(long int num, int size);

#endif
