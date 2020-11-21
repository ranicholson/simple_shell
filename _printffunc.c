#include "holberton.h"

/**
 * format_u - prints an unsigned int in decimal
 * @n: int to be printed
 *
 * Return: number of characters printed
 */

int format_u(unsigned int n)
{
	int cc = 0;

	if (n / 10)
		cc += format_u(n / 10);

	_putchar((n % 10) + '0');
	cc++;

	return (cc);
}

#include "holberton.h"

/**
 * format_s - prints a string
 * @s: pointer to string to be printed
 *
 * Return: number of characters printed
 */

int format_s(char *s)
{
	int i, cc = 0;

	if (s == NULL)
	{
		_printf("(null)");
		return (6);
	}

	for (i = 0; s[i] != '\0'; ++i)
	{
		_putchar(s[i]);
		cc++;
	}
	return (cc);
}
#include "holberton.h"

/**
 * format_di - calls a function to print an int in base 10
 * @a: int to be printed
 *
 * Return: number of characters printed
 */

int format_di(int a)
{
	int cc;

	cc = print_number10(a);

	return (cc);
}

/**
 * print_number10 - prints an integer in base 10
 * @n: integer to print
 *
 * Return: number of characters printed
 */

int print_number10(int n)
{
	int cc = 0;

	if (n / 10 == 0 && n < 0)
	{
		_putchar('-');
		cc++;
	}

	if (n / 10)
		cc += print_number10(n / 10);

	if (n % 10 < 0)
	{
		_putchar(-(n % 10) + '0');
		cc++;
	}

	else
	{
		_putchar(n % 10 + '0');
		cc++;
	}
	return (cc);
}

#include "holberton.h"

/**
 * format_c - prints a character
 * @c: character to be printed
 *
 * Return: number of characters printed
 */

int format_c(unsigned char c)
{
	_putchar(c);

	return (1);
}
