#include "main.h"

/**
  * power - function to carry out power of a value
  * @base: value to be powered
  * @exponent: how many times to iterate the loop
  * Return: returns result of the power function
  */

int power(int base, int exponent)
{
	int result = 1;
	int i;

	for (i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return (result);
}
 
/**
  * write_number - writes integers to the stdout
  * @number: value to be printed out
  * @num_char_printed: number of characters printed to stdout
  * Return: returns number of characters printed
 */

int write_number(int number, int num_char_printed)
{
	int num_digits = 0;
	int temp;
	int i;

	if (number == 0)
	{
		char zero = '0';
		
		write(1, &zero, 1);
		num_char_printed++;
	
		return (num_char_printed);
	}

	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
		num_char_printed++;
	}

	temp = number;

	while (temp != 0)
	{
		temp /= 10;
		num_digits++;
	}

	temp = number;

	for (i = (num_digits - 1); i >= 0; i--)
	{
		int digit = temp / power(10, i);
		char individual_char = '0' + digit;

		write(1, &individual_char, 1);
	
		temp %= power(10, i);
		num_char_printed++;
	}
	return (num_char_printed);
}
