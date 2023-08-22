#include "main.h"

/**
 * print_num - prints number
 * @num: integer
 * Return: integer length
 */
int print_num(int num)
{
	int len = 0, rev = 0;

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
