#include "main.h"
/**
 * print_str - Prints a string to stdout.
 * @ap: va_list that holds the string args.
 * Return: Number of chars printed.
 */
int print_str(va_list ap)
{
	char *str;
	int count = 0;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	while (str[count])
	{
		put_char(str[count]);
		count++;
	}
	return (count);
}
