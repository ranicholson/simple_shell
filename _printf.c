#include "holberton.h"

/**
 * _printf - parses input string and calls f_output to choose which function
 * to use for formatting based on specifiers
 * @format: pointer to string containing specifiers
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list arg_list;
	unsigned int i = 0, len = 0;
	int cc = 0, ret = 0;

	if (!format)
		return (-1);

	va_start(arg_list, format);
	while (format[len])
		++len;

	for (i = 0; i < len; ++i)
	{
		if (format[i] == '%')
		{
			++i;
			while (format[i] == ' ')
				i++;
			if (format[i] == '\0')
				return (-1);
			ret = f_output(format[i], &arg_list);
			if (ret < 0)
				return (-1);
			cc += ret;
		}
		else
		{
			_putchar(format[i]);
			cc++;
		}
	}
	va_end(arg_list);
	return (cc);
}

#include "holberton.h"

/**
 * _putchar - writes a character to stdout
 * @c: character to be printed
 *
 * Return: 1 on success, -1 on failure
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

#include "holberton.h"

/**
 * f_output - chooses formatting function based on specifier
 * @f: format specifier
 * @arg_list: list of arguments used to replace format specifiers in string
 *
 * Return: number of characters printed
 */

int f_output(char f, va_list *arg_list)
{
	unsigned char c;
	char *s;
	int cc = 0, d;

	switch (f)
	{
	case 'c':
		c = va_arg(arg_list, int);
		cc += format_c(c);
		break;
	case 's':
		s = va_arg(arg_list, char *);
		cc += format_s(s);
		break;
	case 'i':
	case 'd':
		d = va_arg(arg_list, int);
		cc += format_di(d);
		break;
	default:
		cc += f_output1(f, arg_list);
		break;
	}
	return (cc);
}

/**
 * f_output1 - chooses formatting function based on specifier
 * @f: format specifier
 * @arg_list: list of arguments used to replace format specifiers in string
 *
 * Return: number of characters printed
 */

int f_output1(char f, va_list *arg_list)
{
	int cc = 0;
	unsigned int u;

	switch (f)
	{
	case 'u':
		u = va_arg(arg_list, unsigned int);
		cc += format_u(u);
		break;
	default:
		cc += format_literal(f);
		break;
	}
	return (cc);
}

  
#include "holberton.h"

/**
 * format_literal - prints invalid specifier as a literal
 * @f: format specifier to be printed
 *
 * Return: number of characters printed
 */

int format_literal(char f)
{
	_putchar('%');
	_putchar(f);
	return (2);
}
