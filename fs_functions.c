#include "main.h"

/**
 * print_num - prints number
 * @n: integer
 * Return: integer length
 */
int print_num(int n)
{
	unsigned int m, d, length, count;

	length = 0;

	if (n < 0)
	{
		_putchar(45);
		m = n * -1;
		length++;
	}
	else
	{
		m = n;
	}

	d = m;
	count = 1;

	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (; count >= 1; count /= 10)
	{
		_putchar(((m / count) % 10) + 48);
		length++;
	}
	return (length);
}

/**
 * print_str - prints strings
 * @str: string pointer
 * Return: string length
 */
int print_str(const char *str)
{
	int len = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	while (*str)
	{
		_putchar(*str);
		len++;
		str++;
	}

	return (len);
}

/**
 * print_bin - prints binary
 * @num: unsigned int
 * Return: binary length
 */
int print_bin(unsigned int num)
{
	int len = 0, bit_pos = 31;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (!((num >> bit_pos) & 1))
	{
		bit_pos--;
	}

	while (bit_pos >= 0)
	{
		_putchar((num >> bit_pos) & 1 ? '1' : '0');
		len++;
		bit_pos--;
	}

	return (len);
}
