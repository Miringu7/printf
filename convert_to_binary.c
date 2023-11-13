#include "main.h"

/**
  * convert_to_binary - converts an integer to binary
  * @integer_num: integer value to be converted
  * @num_char_printed: characters printed to the stdout
  * Return: number of characters printed
  */

int convert_to_binary(int integer_num, int num_char_printed)
{
	if (integer_num < 0)
		return (-1);

	if (integer_num == 0)
	{
		char to_binary;

		to_binary = '0' + integer_num;
		write(1, &to_binary, 1);
	}

	if (integer_num > 0)
	{
		num_char_printed = greater_than_zero(integer_num, num_char_printed);
	}
	return (num_char_printed);
}

/**
  * greater_than_zero - converts integers greater than zero to binary
  * @integer_num: the integer to be converted
  * @num_char_printed: characters printed to stdout
  * Return: number of characters printed
  */

int greater_than_zero(int integer_num, int num_char_printed)
{
	char binary_digit;
	char *binary = (char *)malloc(20 * sizeof(char));
	int temp, i = 0;
	int bit_count = 0;

	if (binary == NULL)
	return (-1);

	temp = integer_num;

	while (temp != 0)
	{
		bit_count++;
		temp /= 2;
	}

	temp = integer_num;

	while (temp != 0)
	{
		binary_digit = '0' + temp % 2;

		if (i <= (bit_count - 1))
		binary[i] = binary_digit;

		num_char_printed++;
		i++;

		temp /= 2;
	}

	for (i = (strlen(binary) - 1); i >= 0; i--)
	{
		write(1, &binary[i], 1);
	}
	free(binary);

	return (num_char_printed);
}
