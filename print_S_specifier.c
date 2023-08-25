#include "main.h"

#include "main.h"

/**
 * related_S_specifier - hexa will be printed.
 * @par_num: arguments.
 * Return: counter.
 */
int related_S_specifier(unsigned long int par_num)
{
	unsigned long int temp = par_num;
	long int *_arr, _count = 0, i;

	while (par_num / 16 != 0)
	{
		par_num /= 16;
		_count++;
	}
	_count++;
	_arr = malloc(_count * sizeof(long int));

	for (i = 0; i < _count; i++)
	{
		_arr[i] = temp % 16;
		temp /= 16;
	}
	for (i = _count - 1; i >= 0; i--)
	{
		if (_arr[i] > 9)
			_arr[i] = _arr[i] + 39;
		put_char(_arr[i] + '0');
	}
	free(_arr);
	return (_count);
}

/**
 * print_S_specifier - special king of string logic function.
 * @ap: receive variable list dataType.
 *
 * Return: out_put length (int).
 */
int print_S_specifier(va_list ap)
{
	int len_size = 0, i, _casting;
	char *spe_string;

	spe_string = va_arg(ap, char *);
	if (spe_string == NULL)
		spe_string = "(null)";
	for (i = 0; spe_string[i] != '\0'; i++)
	{
		if (spe_string[i] < 32 || spe_string[i] >= 127)
		{
			put_char('\\');
			put_char('x');
			len_size = len_size + 2;
			_casting = spe_string[i];
			if (_casting < 16)
			{
				put_char('0');
				len_size++;
			}
			len_size = len_size + related_S_specifier(_casting);
		}
		else
		{
			put_char(spe_string[i]);
			len_size++;
		}
	}
	return (len_size);
}
