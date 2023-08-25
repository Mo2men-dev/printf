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

int _printf(const char *format, ...);

int put_char(char c);

int print_char(va_list c);
int print_mod(va_list ap);
int print_str(va_list s);

int print_int(va_list i);
int print_dec(va_list d);

int print_roted(va_list ap);

int print_binSYS(va_list ap);
int decimal_to_bin(int n);

int print_r_specifier(va_list ap);

int print_S_specifier(va_list ap);
int related_S_specifier(unsigned long int par_num);

int print_hexaD(unsigned int num1, unsigned int num2);
int print_lower_hexaD(va_list ap);
int print_upper_hexaD(va_list ap);
int print_octaSYS(va_list ap);
int print_unsigned_int(va_list ap);
int convert_bin_dec(char *binary_string);
char *decimal_to_binary_string(unsigned int decimal);
int _strlen(const char *s);
int print_number(int n);

#endif /* MAIN_H */
