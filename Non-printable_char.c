#include "main.h"
/**
 * print_the_string - prints string
 * @st: values to be printed
 * Return: printed character
 */

int print_the_string(va_list st)
{
	char *str;
	int i = 0;
	int length = 0;
	int v;

	str = va_arg(st, char *);
	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			length = length + 2;
			v = str[i];
			if (v < 16)
			{
				_putchar('0');
				length++;
			}
			length = length + print_uppercase(v);
		}
		else
		{
			_putchar(str[i]);
			length++;
		}
		i++;
	}
	return (length);
}

