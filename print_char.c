#include "main.h"

/**
 * print_char - funciton to print a char .
 * @ap: Argument list that has the char to print.
 *
 * Return: number of chrs to be printed (int).
 */
int print_char(va_list ap)
{
	unsigned char c;

	c = va_arg(ap, int);
	put_char(c);
	return (1);
}
/**
 * print_mod - Function that prints '%' char
 * @ap: va_list arg (not being used)
 * Return: int (1)
*/
int print_mod(va_list ap)
{
	(void)ap;
	put_char('%');
	return (1);
}

