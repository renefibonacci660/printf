#include "holberton.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/**
 * _printf - a function that prints the argument upon its type and format
 * @format: a pointer to first argument
 * @...: ellipse the last place of argument
 *
 * Return: return a total characters of print out
 */

int _printf(const char *format, ...)
{
	int i, len, p_total;
	char *s;
	va_list ap;
	char *(*pointer_get_arg)(va_list);
	char *v = "%";

	if (format == NULL || strcmp(format, v) == 0)
		return (-1);
	len = p_total = 0;
	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			pointer_get_arg = get_arg_type(format[i + 1]);
			if (pointer_get_arg == NULL)
				s = found_nothing(format[i + 1]);
			else
				s = pointer_get_arg(ap);
			if ((format[i + 1] == 'c' || format[i + 1] == 'C') && (s == NULL))
			{
				_putchar('\0');
				i++;
			}
			else
			{
				i++;
				len = _strlen(s);
				p_total += len;
				while (*s)
					_putchar(*s++);
			}
		}
		else
		{
			_putchar(format[i]);
			p_total++;
		}
	}
	va_end(ap);
	return (p_total);
}
