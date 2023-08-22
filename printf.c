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

		va_start(args, format);
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] == '%' && format[i - 1] != '%')
			{
				if (format[i + 1] == '\0')
					return (-1);
				if (format[i + 1] == ' ')
				{
					length += process_format_specifier(args, format[i + 2]);
					i = i + 2;
					return (-1);
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
	int num, length = 0;
	unsigned int num1;
	char *str;

	switch (specifier)
	{
		case 'b':
			num1 = va_arg(args, unsigned int);

			length += print_bin(num1);
			break;
		case 'c':
			_putchar(va_arg(args, int)), length++;
			break;
		case 'd':
		case 'i':
			num = va_arg(args, int);

			if (num < 0)
			{
				_putchar('-'), length++;
				num = -num;
			}
			length += print_num(num);
			break;
		case 's':
			str = va_arg(args, char *);

			if (str == NULL)
				str = "(null)";
			length += print_str(str);
			break;
		case '%':
			_putchar('%'), length++;
			break;
		default:
			_putchar('%'), _putchar(specifier), length = length + 2;
			break;
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
