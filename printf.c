#include "printf.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - similar to printf
 *
 * @format: character string
 * Return: length
 */
int _printf(const char *format, ...)
{
	int i, j, length;
	char *str;
	va_list args;

	length = 0;

	if (format)
	{
		va_start(args, format);
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i - 1] == '%')
			{
				switch (format[i])
				{
					case 'c':
						_putchar(va_arg(args, int)), length++;
						break;
					case 's':
						str = va_arg(args, char *);
						for (j = 0; str[j] != '\0'; j++)
							_putchar(str[j]), length++;
						break;
					case '%':
						_putchar('%'), length++;
						break;
					default:
						break;
				}
				continue;
			}
			if (format[i] != '%')
				_putchar(format[i]), length++;
		}
		_putchar('\0');
		va_end(args);
		return (length);
	}
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
