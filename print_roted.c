#include "main.h"

/**
 * print_roted - a string is encoded to roted of 13.
 * @ap: receiving a string to be converted.
 * Return: return value (int) refers to the output text size.
 */
int print_roted(va_list ap)
{
	char out_put[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";
	char *ptr_r;
	char in_put[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	int len = 0, j, i;

	ptr_r = va_arg(ap, char *);
	if (ptr_r == NULL)
		ptr_r = "(null)";
	for (j = 0; ptr_r[j] != '\0'; j++)
	{
		for (i = 0; in_put[i] != '\0'; i++)
		{
			if (ptr_r[j] == in_put[i])
			{
				put_char(out_put[i]);
				len++;
				break;
			}
		}
	}
	return (len);
}
