#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

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

	n = va_arg(num, int);
	i = 0;
	tens = 1;
	if (n > 0)
	{
		res = n;
		count = 0;
	}
	else
	{
		res = (n * -1);
		count = 1;
	}
	temp = res;
	while (temp >= 10)
	{
		tens *= 10;
		temp /= 10;
		count++;
	}
	str = malloc((count + 1));
	if (n < 0)
		str[i++] = '-';
	while (tens >= 1)
	{
		str[i++] = (((res / tens) % 10) + '0');
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
	str = malloc((count + 1));
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
	str = malloc((count + 1));
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
 * @hex: name for hexidemical list call
 * Return: return pointer to the converted string
 */

char *found_hex(va_list hex)
{
	unsigned int i, res, tens, temp, count;
	char *str;

	res = va_arg(hex, unsigned int);
	count = i = 0;
	tens = 1;
	temp = res;
	while (temp >= 16)
	{
		tens *= 16;
		temp /= 16;
		count++;
	}
	str = malloc((count + 1));
	while (tens >= 1)
	{
		str[i++] = (((res / tens) % 16) + '0');
		tens /= 16;
	}
	str[i] = '\0';
	return (str);
}

/**
 * _strlen - a function that returns the length of string
 *@s: a pointer of string
 *
 * Return: the length of string
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; *s; i++)
		s++;
	return (i);
}
