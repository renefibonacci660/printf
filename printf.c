#include "holberton.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _printf - a function that prints the argument upon its type and format
 * @format: a pointer to first argument
 * @...: ellipse the last place of argument
 *
 * Return: return a total characters of print out
 */

int _printf(const char *format, ...)
{
	int i, j, len, p_total;
	char *s;
	va_list ap;
	char *(*pointer_get_arg)(va_list);

	pointer_get_arg == NULL;
	len = p_total = 0;
	va_start(ap, format);
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			pointer_get_arg = get_arg_type(format[i + 1]);
			s = (!pointer_get_arg) ? found_nothing(format[i + 1]) : pointer_get_arg(ap);
			i++;
			len = _strlen(s);
			p_total += len;
			while (*s)
				_putchar(*s++);
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