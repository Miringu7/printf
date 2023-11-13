#include "main.h"

/**
  * write_octal_num - writes octal numbers to the stdout
  * @unsigned_octal_num: value to be printed out
  * @num_char_printed: number of characters printed to stdout
  * Return: returns number of characters printed
 */

int write_octal_num(int unsigned_octal_num, int num_char_printed)
{
	unsigned int num_digits = 0;
	unsigned int temp;
	int i;

	if (unsigned_octal_num == 0)
	{
		char zero = '0';

		write(1, &zero, 1);
		num_char_printed++;

		return (num_char_printed);
	}

	else
	{
		temp = unsigned_octal_num;

		while (temp != 0)
		{
			temp /= 8;
			num_digits++;
		}

		temp = unsigned_octal_num;

		for (i = (num_digits - 1); i >= 0; i--)
		{
			unsigned int digit = temp / unsigned_power(8, i);
			char individual_char = '0' + digit;

			write(1, &individual_char, 1);

			temp %= unsigned_power(8, i);
			num_char_printed++;
		}
	}
	return (num_char_printed);

}
