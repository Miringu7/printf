#include "main.h"

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
