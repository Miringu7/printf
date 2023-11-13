#include "main.h"

/**
  * specifier_c - checks if character is a char specify
  * @character: character to be checked
  * @num_char_printed: number of characters printed to stdout
  * Return: returns number of characters printed
  */

int specifier_c(char *character, int num_char_printed);
int write_number(int number, int num_char_printed);

/**
  * _printf - function that produces output according to a format.
  * @format: first argument to the my_printf function
  * Return: characters printed
  */

int _printf(const char *format, ...)
{
	int num_char_printed = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			num_char_printed++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				char character = va_arg(args, int);

				write(1, &character, 1);
				num_char_printed++;
			}
			else if (*format == 's')
			{
				char *string = va_arg(args, char*);
				int string_length = strlen(string);

				write(1, string, string_length);
				num_char_printed += string_length;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				num_char_printed++;
			}
			else if (*format == 'd' || *format == 'i')
			{
				int integer = va_arg(args, int);

				num_char_printed = write_number(integer, num_char_printed);

			}
		}
		format++;
	}
	va_end(args);
	return (num_char_printed);
}

/**
 * specifier_c - checks if character is a char specify
 * @character: character to be checked
 * @num_char_printed: number of characters printed to stdout
 * Return: returns number of characters printed
 */

int specifier_c(char *character, int num_char_printed)
{
	write(1, character, 1);
	num_char_printed++;

	return (num_char_printed);
}

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
