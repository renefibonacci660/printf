#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * found_char - a function that find argument type is c
 * @c: va_list c
 *
 * Return: return argument as string
 */
char *found_char(va_list c)
{
	char str[2];
	char *s;

	s = str;
	str[0] = va_arg(c, int);
	str[1] = '\0';
	return (s);
}

/**
 * found_string - a function find next argument is string
 * @s: pointer to string
 *
 * Return: return the pointer of string
 */
char *found_string(va_list *s)
{
	char *str;

	str = va_arg(s, char *);
	if (str == NULL)
		return ("null");
	return (str);
}

/**
 * found_percent - a function find a character %
 *
 * Return: return a string of %
 */
char *found_percent(void)
{
	char *str;

	str = "%";
	return (str);
}
/**
 * found_nothing - a function find nothing match the type after %
 * @c: a character after %
 *
 * Return: return pointer of string
 */
char *found_nothing(char c)
{
	char str[3];
	char *s;

	s = str;
	str[0] = '%';
	str[1] = c;
	str[2] = '\0';
	return (s);
}
