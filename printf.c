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
				if (format[i + 1] == '\0')
					return (-1);
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
	int length = 0,num, j;
	char *str;

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
		case 'd':
		case 'i':
			num = va_arg(args, int);

			if (num < 0)
			{
				_putchar('-');
				length++;
				num = -num;
			}
			length += print_number(num);
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
 * print_number - prints intergers
 * @num: number to be worked on
 * Return: 1 if failed, len if successful
 */
int print_number(int num)
{
	int len = 0;
	int rev = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		rev = rev * 10 + num % 10;
		num /= 10;
	}

	while (rev > 0)
	{
		_putchar('0' + rev % 10);
		rev /= 10;
		len++;
	}

	return (len);
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
