#include "main.h"

/**
  * write_unsigned_number - writes integers to the stdout
  * @number: value to be printed out
  * @num_char_printed: number of characters printed to stdout
  * Return: returns number of characters printed
 */

int write_unsigned_number(unsigned int number, int num_char_printed)
{
	unsigned int num_digits = 0;
	unsigned int temp;
	int i;

	if (number == 0)
	{
		char zero = '0';

		write(1, &zero, 1);
		num_char_printed++;

		return (num_char_printed);
	}

	else if (number > 0)
	{
		temp = number;

		while (temp != 0)
		{
			temp /= 10;
			num_digits++;
		}

		temp = number;

		for (i = (num_digits - 1); i >= 0; i--)
		{
			unsigned int digit = temp / power(10, i);
			char individual_char = '0' + digit;

			write(1, &individual_char, 1);

			temp %= power(10, i);
			num_char_printed++;
		}
	}
	return (num_char_printed);
}
