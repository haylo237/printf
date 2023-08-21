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

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%' && format[i - 1] != '%')
		{
			if (format[i + 1] == ' ')
			{
				length += process_format_specifier(args, format[i + 2]);
				i = i + 2;
				continue;
			}
			length += process_format_specifier(args, format[i + 1]);
			i++;
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
 * process_format_specifier - checks for specifiers
 * @args: arguments
 * @specifier: switch cases
 * Return: integer
 */
int process_format_specifier(va_list args, char specifier)
{
	int length;

	length = 0;

	switch (specifier)
	{
		case 'c':
			_putchar(va_arg(args, int));
			length++;
			break;
		case 's':
			char *str;
			str = va_arg(args, char *);
			int j;

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
