#include "main.h"
/**
 * str_reverse - prints string in reverse
 * @rev: this is an argument
 * Return: it will return the string
 */

int str_reverse(va_list rev)
{
	int x;
	int y;
	char *st = va_arg(rev, char *);

	if (st == NULL)
		st = "(null)";
	while (st[x] != '\0')
		x++;
	for (y = x - 1; y >= 0; y--)
		_putchar(st[y]);
	return (x);
}
