#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <stdio.h>

/**
 * _printf: produces output according to a format
 * @format: the format string
 * Return: The number of characters printed
*/

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	char *str;

	va_start (args, format);

	while (format && *format)
	{
		if (*format != '%')
		{
			write (1,format,1);
			i++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				write (1, &c, 1);
				i++;
			}

			else if (*format == 's')
			{
				str = va_arg(args, char *);
				if (str)
				{
					while (*str)
					{
						write (1, str, 1);
						str++;
						i++;
					}
				}

				else
				{
					write (1, ("NULL"), 6);
					i += 6;
				}
			}

			else if (*format == '%')
			{
				write (1, "%", 1);
				i++;
			}
		}
		format++;
	}
	va_end(args);
	return (i);
}
