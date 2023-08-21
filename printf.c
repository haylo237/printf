#include "main.h"
/**
 * _printf - similar to printf
 *
 * @format: character string
 * Return: length
 */
int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;

            if (*format == 'c') {
                int c = va_arg(args, int);
                _putchar(c);
                count++;
            } else if (*format == 's') {
                char *s = va_arg(args, char *);
                while (*s) {
                    _putchar(*s);
                    s++;
                    count++;
                }
            } else if (*format == '%') {
                _putchar('%');
                count++;
            }
        } else if (*format == '%') {
            format++;
            _putchar('%');
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
