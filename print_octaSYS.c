#include "main.h"

/**
 * print_octaSYS - convert unsigned int to octal.
 * @ap: receive unsigned int.
 *
 * Return: output length (int).
 */
int print_octaSYS(va_list ap)
{
	unsigned int len_size, temp, number, power, j, dig;
	int _counter = 0;

	temp = va_arg(ap, unsigned int);
	if (temp != 0)
	{
		number = temp;
		len_size = 0;
		while (number != 0)
		{
			number /= 8;
			len_size++;
		}
		power = 1;
		for (j = 1; j <= len_size - 1; j++)
			power *= 8;
		for (j = 1; j <= len_size; j++)
		{
			dig = temp / power;
			put_char(dig + '0');
			_counter++;
			temp -= dig * power;
			power /= 8;
		}
	}
	else
	{
		put_char('0');
		return (1);
	}
	return (_counter);
}
