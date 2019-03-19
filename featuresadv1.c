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
	str = malloc((count + 1));
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
	str = convert_add(res, 16, 0);
	return (str);
}
