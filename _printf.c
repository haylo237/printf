#include "main.h"

/**
 * _printf - similar to printf
 *
 * @format: character string
 * Return: length
 */
int _printf(const char *format, ...)
{
	int i, length;
	va_list args;

	length = 0;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				length++;
				i++;
			}
			else if (format[i + 1] != '\0')
			{
				if (format_switch(args, format[i + 1], &length) == -1)
					return (-1);
				i++;
			}
		}
		else
		{
			_putchar(format[i]);
			length++;
		}
	}

	va_end(args);

	return (length);
}
/**
 * format_switch - checks for specifiers
 * @args: arguments
 * @specifier: switch cases
 * @length: ...
 * Return: integer
 */
int format_switch(va_list args, char specifier, int *length)
{
	switch (specifier)
	{
		case 'c':
			_putchar(va_arg(args, int));
			(*length)++;
			break;
		case 's':
			{
				char *str = va_arg(args, char *);
				int j;

				for (j = 0; str[j] != '\0'; j++)
				{
					_putchar(str[j]);
					(*length)++;
				}
			}
			break;
		case '%':
			_putchar('%');
			(*length)++;
			break;
		default:
			return (-1);
	}
	return (0);
}
/**
 * _putchar - similar to putchar
 *
 * @c: character to be printed
 * Return: 0 if successful
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
