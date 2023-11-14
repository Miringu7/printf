#include "main.h"
/**
 * print_specifier_p - prints a pointer
 * @pointer_p: this is the value to be printed
 * Return: it returns integer
 */

int print_specifier_p(va_list pointer_p)
{
	void *pt;
	char *str = "(nil)";
	int i = 0;
	int d;
	long int c;

	pt = va_arg(pointer_p, void *);
	if (pt == NULL)
	{
		while (str[i] != '\0')
		{
			_putchar(str[i]);
			return (i);
			i++;
		}
	}
	c = (unsigned long int)pt;
	_putchar('0');
	_putchar('x');
	d = convert_hex(c);
	return (d + 2);

}
