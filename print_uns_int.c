#include "main.h"

/**
 * decimal_to_binary_string - dec to bin logic function.
 * @decimal: recieve unsigned int dataType.
 *
 * Return: char value returned.
*/
char *decimal_to_binary_string(unsigned int decimal)
{
	int numBits = 0;
	unsigned int temp = decimal;
	char *binaryString;
	int i = 0;
	int start;
	int end;

	if (temp == 0)
		numBits = 1;
	else
		while (temp > 0)
		{
			numBits++;
			temp /= 2;
		}

	binaryString = (char *)malloc(numBits + 1);

	if (binaryString == NULL)
		return (NULL);

	for (i = 0; i < numBits; i++)
	{
		binaryString[i] = '0' + (decimal % 2);
		decimal /= 2;
	}

	binaryString[numBits] = '\0';
	start = 0;
	end = numBits - 1;
	while (start < end)
	{
		char temp = binaryString[start];

		binaryString[start] = binaryString[end];
		binaryString[end] = temp;
		start++;
		end--;
	}
	return (binaryString);
}

/**
 * convert_bin_dec - bin to dec logic function.
 * @binary_string: recieve unsigned pointer to char dataType.
 *
 * Return: int value returned.
*/
int convert_bin_dec(char *binary_string)
{
	int length = _strlen(binary_string);
	int decimal = 0;
	int base = 1;
	int i = length - 1;

	while (i >= 0)
	{
		if (binary_string[i] == '1')
		{
			decimal += base;
		}
		base *= 2;
		i--;
	}
	free(binary_string);
	return (decimal);
}

/**
 * print_unsigned_int - handling uns_int to be printed with %u
 * @ap: recieve variable list dataType.
 *
 * Return: int value returned.
*/
int print_unsigned_int(va_list ap)
{
	int count = 0;
	unsigned int n = va_arg(ap, unsigned int);
	unsigned int n1 = convert_bin_dec(decimal_to_binary_string(n));

	if (n1 / 10)
	{
		count = print_number(n1 / 10);
	}
	put_char((n1 % 10) + '0');
	return (count + 1);
}
