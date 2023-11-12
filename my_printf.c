#include "main.h"

/**
  *
  *
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

			int character = va_arg(args, int);

			if (*format == 'c')
			{
				write(1, character, 1);
			}

			if (*format == 's')
			{
				while (*character)
			}

		}
		num_char_printed++;
	}
	return (num_char);
}
