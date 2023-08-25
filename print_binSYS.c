#include "main.h"

/**
 * decimal_to_bin - decimal number to binary number convertor.
 * @n: converted decimal number.
 *
 * Return: Count of digits in binary (int).
 */
int decimal_to_bin(int n)
{
	int count = 0;

	if (n > 1)
	{
		decimal_to_bin(n / 2);
	}

	put_char((n % 2) + '0');
	count++;
	return (count);
}

/**
 * print_binSYS - binary representatoin of integer function.
 * @ap: variable argument contains the integer num to be converted and printed.
 *
 * Return: count of digits (int).
 */
int print_binSYS(va_list ap)
{
	int num = va_arg(ap, int);

	return (decimal_to_bin(num));
}
