#include "main.h"
/**
 * prints_rot13 - a function that converts rot13
 * @Rot13: its an argument
 * Return: it returns count
 */

int prints_rot13(va_list Rot13)
{
	int x, y;
	int count = 0;
	int n = 0;
	char *st = va_arg(Rot13, char *);
	char w[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char v[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (st == NULL)
		st = "(null)";
	for (x = 0; st[x]; x++)
	{
		n = 0;
		for (y = 0; w[y] && !n; y++)
		{
			if (st[x] == w[y])
			{
				_putchar(v[y]);
				count++;
				n = 1;
			}
		}
		if (!n)
		{
			_putchar(st[x]);
			count++;
		}
	}
	return (count);
}
