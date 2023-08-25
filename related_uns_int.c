#include "main.h"

/**
 * _strlen - Compute the length of a string.
 * @s: Pointer to a string.
 * Return: Length of the string.
*/
int _strlen(const char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * print_number - Print an integer as a series of digits.
 * @n: The integer to be printed.
 * Return: Number of characters printed.
*/
int print_number(int n)
{
	unsigned int n1 = 0;
	int count = 0;

	if (n < 0)
	{
		n1 = -n;
		put_char('-');
	}
	else
	{
		n1 = n;
	}

	if (n1 / 10)
	{
		count = print_number(n1 / 10);
	}
	put_char((n1 % 10) + '0');
	return (count + 1);
}

