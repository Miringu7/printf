#include "main.h"

int power(int base, int exponent);
unsigned int unsigned_power(unsigned int base, unsigned int exponent);
int write_string(char *string, int num_char_printed);

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
				num_char_printed = write_string(string, num_char_printed);
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
			else if (*format == 'b')
			{
				int integer_num = va_arg(args, int);

				num_char_printed = convert_to_binary(integer_num, num_char_printed);
			}
			else if (*format == 'u')
			{
				int unsigned_num = va_arg(args, int);

				num_char_printed = write_unsigned_number(unsigned_num, num_char_printed);
			}
			else if (*format == 'o')
			{
				int unsigned_octal_num = va_arg(args, int);

				num_char_printed = write_octal_num(unsigned_octal_num, num_char_printed);
			}
			else if (*format == 'x')
			{
				int unsigned_hex_num = va_arg(args, int);

				num_char_printed = write_hex_num(unsigned_hex_num, num_char_printed);
			}
			else if (*format == 'X')
			{
				int unsigned_HEX_num = va_arg(args, int);

				num_char_printed = write_HEX_num(unsigned_HEX_num, num_char_printed);
			}

		}
		format++;
	}
	va_end(args);
	return (num_char_printed);
}
/**
  *  write_string - function that produces output according to a format.
  * @string: string to be printed out
  * @num_char_printed: number of characted already printed
  * Return: characters printed
*/
int write_string(char *string, int num_char_printed)
{
	int string_length = strlen(string);
	write(1, string, string_length);
	num_char_printed += string_length;
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
  * power - function to carry out power of a value
  * @base: value to be powered
  * @exponent: how many times to iterate the loop
  * Return: returns result of the power function
  */

unsigned int unsigned_power(unsigned int base, unsigned int exponent)
{
	unsigned int result = 1;
	unsigned int i;

	for (i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return (result);
}
