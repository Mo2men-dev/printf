#include "main.h"
/**
 * put_char - Writes a char to stdout to be printed.
 * @c: char to be written.
 *
 * Return: returns (int) num of bytes written. On failure, returns -1.
 */
int put_char(char c)
{
	return (write(1, &c, 1));
}
