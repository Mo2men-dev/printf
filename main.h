#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

/**
 * struct format - hadles a format string and its funcs.
 * @format_specifier: a variable for some chars specifirs in string.
 * @format: handle specifiers in a string format.
 *
 * Discription: struct to handle a formatted string contins chars specifiers.
*/
typedef struct format
{
	char *format_specifier;
	int (*format)(va_list ap);
} format_matcher;

int put_char(char c);
int _printf(const char *format, ...);
int print_char(va_list c);
int print_str(va_list s);
int print_int(va_list i);
int print_dec(va_list d);
int print_mod(va_list ap);

#endif /* MAIN_H */

