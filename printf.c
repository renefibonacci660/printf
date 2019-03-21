#include "holberton.h"
#include <stdarg.h>
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
	int i, j, len, len_buf, p_total;
	char *s, *str;
	static char buffer[1024];
	va_list ap;
	char *(*pointer_get_arg)(va_list);
	char *v = "%";

	str = &buffer[0];
	for (j = 0; j < 1024; j++)
		buffer[j] = 0;
	if (format == NULL || strcmp(format, v) == 0)
		return (-1);
	len = p_total = len_buf = 0;
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
				p_total++;
				i++;
			}
			else
			{
				i++;
				len = _strlen(s);
				if (*str)
					len_buf = _strlen(str);
				if (len > 1023)
				{
					_puts(s, len);
					p_total += len;
				}
				else if ((len_buf + len) > 1024)
				{
					_puts(buffer, len_buf);
					p_total += len_buf;
					for (j = 0; j <= 1024; j++)
						buffer[j] = 0;
					str = _memcopy(str, s, 0);
				}
				else
					str = _memcopy(str, s, len_buf);
			}
		}
		else
		{
			s = ctos(format[i]);
			if (*str)
				len_buf = _strlen(str);
			str = _memcopy(str, s, len_buf);
		}
	}
	va_end(ap);
	if (*str)
		len_buf = _strlen(str);
	_puts(str, len_buf);
	p_total += len_buf;
	return (p_total);
}
