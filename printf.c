#include "main.h"
/**
 * _printf - similar to printf
 *
 * @format: character string
 * Return: length
 */
int _printf(const char *format, ...)
{
	va_list args;

	int length = 0;
	int i = 0;

	if (format == NULL)
        return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break;

			if (format[i] == '%')
			{
				_putchar('%');
				length++;
			}
			else if (format[i] == 'c')
			{
				char c = va_arg(args, int);
				_putchar(c);
				length++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";

				while (*str)
				{
					_putchar(*str);
					str++;
					length++;
				}
			}
			else
			{
				_putchar('%');
				_putchar(format[i]);
				length += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			length++;
		}
		i++;
	}

	va_end(args);
	return (length);
}
/**
 * process_format_specifier - checks for specifiers
 * @args: arguments
 * @specifier: switch cases
 * Return: integer
 */
int process_format_specifier(va_list args, char specifier)
{
	int length, j;
	char *str;

	length = 0;

	switch (specifier)
	{
		case 'c':
			_putchar(va_arg(args, int));
			length++;
			break;
		case 's':
			str = va_arg(args, char *);

			if (str == NULL)
				str = "(null)";
			for (j = 0; str[j] != '\0'; j++)
			{
				_putchar(str[j]);
				length++;
			}
			break;
		case '%':
			_putchar('%');
			length++;
			break;
		default:
			return (-1);
	}
	return (length);
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
