#include "main.h"

/**
  * write_hex_num - writes octal numbers to the stdout
  * @unsigned_hex_num: value to be printed out
  * @num_char_printed: number of characters printed to stdout
  * Return: returns number of characters printed
 */


int write_hex_num(int unsigned_hex_num, int num_char_printed)
{
	unsigned int num_digits = 0;
	unsigned int temp;
	int i;

	temp = unsigned_hex_num;

	while (temp != 0)
	{
		temp /= 16;
		num_digits++;
	}

	temp = unsigned_hex_num;

	for (i = (num_digits - 1); i >= 0; i--)
	{
		char individual_char = temp / unsigned_power(16, i);

		if (individual_char < 10)
			individual_char += '0';

		else
			individual_char += 'a' - 10;

		write(1, &individual_char, 1);

		temp %= unsigned_power(16, i);
		num_char_printed++;
	}

	return (num_char_printed);
}
