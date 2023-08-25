#include "main.h"

/**
* print_hexaD - unsigned int to hexa_decimal handling function.
* @num1: recieved an unsigned (int) .
* @num2: print state [0] if lower, [1] if upper.
* Return: count of the out_put.
*/
int print_hexaD(unsigned int num1, unsigned int num2)
{
	unsigned int num, len_size, dig, power, j;
	int _counter = 0;
	char ch;

	if (num1 != 0)
	{
		num = num1;
		len_size = 0;
		if (num2)
			ch = 'A' - ':';
		else
			ch = 'a' - ':';
		while (num != 0)
		{
			num /= 16;
			len_size++;
		}
		power = 1;
		for (j = 1; j <= len_size - 1; j++)
			power *= 16;
		for (j = 1; j <= len_size; j++)
		{
			dig = num1 / power;
			if (dig < 10)
				put_char(dig + '0');
			else
				put_char(dig + '0' + ch);
			_counter++;
			num1 -= dig * power;
			power /= 16;
		}
	}
	else
	{
		put_char('0');
		return (1);
	}
	return (_counter);
}

/**
* print_lower_hexaD - unsigned int prints to hexa lowercase system.
* @ap: recieve unsigend int.
*
* Return: out_put length. (int)
*/
int print_lower_hexaD(va_list ap)
{
	return (print_hexaD(va_arg(ap, unsigned int), 0));
}

/**
* print_upper_hexaD - unsigned int to Uppercase hexa.
* @ap: recieve uns_int.
*
* Return: out_put lenght.
*/
int print_upper_hexaD(va_list ap)
{
	return (print_hexaD(va_arg(ap, unsigned int), 1));
}
