#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * found_int - a function that coverts integer to string
 * @num: a number from argument
 *
 * Return: return a pointer to int string
 */
char *found_int(va_list num)
{
	int n, i, tens, res, temp, count;
	char *str;
	static char buffer[50];

	str = &buffer[0];
	n = va_arg(num, int);
	i = count = 0;
	tens = 1;
	(n > 0) ? (res = n * -1) : (res = n, count = 1);
	temp = res;
	while (temp <= -10)
	{
		tens *= 10;
		temp /= 10;
		count++;
	}
	if (n < 0)
		str[i++] = '-';
	while (tens >= 1)
	{
		str[i++] = (((res / tens) % 10) * -1 + '0');
		tens /= 10;
	}
	str[i] = '\0';
	return (str);
}

/**
 * found_unsigned - a function converts unsigned integer to string
 * @unsign: next argument type
 *
 * Return: return pointer to the converted string
 */
char *found_unsigned(va_list unsign)
{
	unsigned int i, res, tens, temp, count;
	char *str;
	static char buffer[50];

	str = &buffer[0];
	res = va_arg(unsign, unsigned int);
	count = i = 0;
	tens = 1;
	temp = res;
	while (temp >= 10)
	{
		tens *= 10;
		temp /= 10;
		count++;
	}
	while (tens >= 1)
	{
		str[i++] = (((res / tens) % 10) + '0');
		tens /= 10;
	}
	str[i] = '\0';
	return (str);
}


/**
 * found_octal - a function converts unsigned integer to octal
 * @octal: next argument type
 *
 * Return: return pointer to the converted string
 */
char *found_octal(va_list octal)
{
	unsigned int i, res, tens, temp, count;
	char *str;
	static char buffer[50];

	str = &buffer[0];
	res = va_arg(octal, unsigned int);
	count = i = 0;
	tens = 1;
	temp = res;
	while (temp >= 8)
	{
		tens *= 8;
		temp /= 8;
		count++;
	}
	while (tens >= 1)
	{
		str[i++] = (((res / tens) % 8) + '0');
		tens /= 8;
	}
	str[i] = '\0';
	return (str);
}


/**
 * found_hex - a function converts unsigned integer to hexidecimal
 * @hex: next argument parameter
 * Return: return pointer to the converted string
 */
char *found_hex(va_list hex)
{
	unsigned int res;
	char *str;

	res = va_arg(hex, unsigned int);
	str = convert(res, 16, 0);
	return (str);
}

/**
 * found_HEX - a function converts unsigned integer to hexidecimal
 * @HEX: next argument parameter
 * Return: return pointer to the converted string
 */
char *found_HEX(va_list HEX)
{
	unsigned int res;
	char *str;

	res = va_arg(HEX, unsigned int);
	str = convert(res, 16, 1);
	return (str);
}
