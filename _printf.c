#include "main.h"
/**
  * find_function - function that finds formats for _printf
  * and calls the corresponding function.
  * @format: format (c, s, i, d)
  * Return: NULL or function associated with the format.
  */
int (*find_function(const char *format))(va_list)
{
	unsigned int i = 0;
	format_matcher find_f[] = {
		{"c", print_char},
		{"s", print_str},
		{"i", print_int},
		{"d", print_dec},
		{"%", print_mod},
		{NULL, NULL}
	};

	while (find_f[i].format_specifier)
	{
		if (find_f[i].format_specifier[0] == (*format))
			return (find_f[i].format);
		i++;
	}
	return (NULL);
}
/**
  * _printf - Alternative function to printf.
  * @format: format (c, s, i, d)
  * Return: size the printed string.
  */
int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	unsigned int i = 0, count = 0;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			put_char(format[i]);
			count++;
			i++;
		}
		if (format[i] == '\0')
			return (count);
		f = find_function(&format[i + 1]);
		if (f != NULL)
		{
			count += f(ap);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		put_char(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(ap);
	return (count);
}

