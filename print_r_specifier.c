#include "main.h"

/**
*print_r_specifier - reverse a string logic funciton.
*@ap: recieve a string will be printed.
*Return: length of chars out_put.
*/
int print_r_specifier(va_list ap)
{
	int b = 0;
	int a;

	char *string_rev = va_arg(ap, char*);

	if (string_rev == NULL)
		string_rev = "(null)";

	while (string_rev[b] != '\0')
		b++;

	for (a = b - 1; a >= 0; a--)
		put_char(string_rev[a]);

	return (b);
}

