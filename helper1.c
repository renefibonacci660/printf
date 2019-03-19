#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * convert - a function that converts int to string upon the base
 * @num: number to be converted
 * @base: converting to upon the base
 * @flag: 0 for lowercase, 1 for uppercase
 *
 * Return: return pointer to string
 */
char *convert(unsigned int num, int base, int flag)
{
	static char *array;
	static char buffer[50];
	char *ptr;

	array = (flag == 1) ? ("0123456789ABCDEF") : ("0123456789abcdef");
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = array[num % base];
		num /= base;
	} while (num != 0);
	return (ptr);
}

/**
 * convert_add - a function that converts int to string upon the base
 * @num: number to be converted
 * @base: converting to upon the base
 * @flag: 0 for lowercase, 1 for uppercase
 *
 * Return: return pointer to string
 */
char *convert_add(unsigned long num, unsigned long base, int flag)
{
	static char *array;
	static char buffer[50];
	char *ptr;

	array = (flag == 1) ? ("0123456789ABCDEF") : ("0123456789abcdef");
	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = array[num % base];
		num /= base;
	} while (num != 0);
	*--ptr = 'x';
	*--ptr = '0';
	return (ptr);
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
