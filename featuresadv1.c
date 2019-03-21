#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * found_bin - a function converts unsigned integer to binary
 * @bin: next argument type
 *
 * Return: return pointer to the converted string
 */
char *found_bin(va_list bin)
{
	unsigned int i, res, tens, temp, count;
	char *str;
	static char buffer[100];

	str = &buffer[0];
	res = va_arg(bin, unsigned int);
	count = i = 0;
	tens = 1;
	temp = res;
	while (temp >= 2)
	{
		tens *= 2;
		temp /= 2;
		count++;
	}
	while (tens >= 1)
	{
		str[i++] = (((res / tens) % 2) + '0');
		tens /= 2;
	}
	str[i] = '\0';
	return (str);
}

/**
 * found_add - a function converts unsigned integer to hexidecimal string
 * @add: next argument parameter
 * Return: return pointer to the converted string
 */
char *found_add(va_list add)
{
	unsigned long res;
	char *str;

	res = va_arg(add, unsigned long);
	if (res == 0)
		return ("(nil)");
	str = convert_add(res, 16, 0);
	return (str);
}

/**
 * found_unprint - a function converts unprintable character to \xHEX format
 * @unprt: a next argument
 *
 * Return: return a pointer to string
 */
char *found_unprint(va_list *unprt)
{
	char *str, *str_new, *s;
	unsigned int len, asci;
	static char buffer[1000];

	str_new = &buffer[999];
	str = va_arg(unprt, char *);
	if (str == NULL)
		return ("(null)");
	len = _strlen(str);
	*str_new = '\0';
	while (len > 0)
	{
		asci = str[--len];
		if (asci < 32 || asci >= 127)
		{
			s = convert_unprt(asci, 16);
			*--str_new = s[1];
			*--str_new = s[0];
			*--str_new = 'x';
			*--str_new = '\\';
		}
		else
		{
			*--str_new = str[len];
		}
	}
	return (str_new);
}
