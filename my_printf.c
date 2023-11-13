#include "main.h"

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

				write(1, character, 1);
				num_char_printed++;
			}
			else if (*format == 's')
			{
				char *string = va_arg(args, char*);
				int string_length = strlen(*string);
				
				write(1, string, (string_length - 1));
				num_char_printed += (string_length - 1);
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				num_char_printed++;
			}
		}
		format++;
	}
	va_end(args);
	return (num_char);
}
