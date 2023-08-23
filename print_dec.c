#include "main.h"

/**
 * print_dec - Prints a decimal.
 * @ap: Argument list that has the int to print.
 *
 * Return: (decimal) num refers to num of numbers to be printed.
 */

int print_dec(va_list ap)
{
	int len, pow, j, dig, number, count = 0, num;

	number = va_arg(ap, int);
	if (number != 0)
	{
		if (number < 0)
		{
			put_char('-');
			count++;
		}
		num = number;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		pow = 1;
		for (j = 1; j <= len - 1; j++)
			pow *= 10;
		for (j = 1; j <= len; j++)
		{
			dig = number / pow;
			if (number < 0)
				put_char((dig * -1) + 48);
			else
				put_char(dig + '0');
			count++;
			number -= dig * pow;
			pow /= 10;
		}
	}
	else
	{
		put_char('0');
		return (1);
	}
	return (count);
}
