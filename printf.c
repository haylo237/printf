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

	if (format == NULL)
		return (-1);

	while (format)
	{
		va_start(args, format);
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
			if (str == "(null)")
				return (6);
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
