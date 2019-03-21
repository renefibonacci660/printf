#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _puts - a function that prints string
 * @buffer: a buffer holds the string
 * @size: size of buffer
 *
 * Reture: void
 */
void _puts(char *buffer, int size)
{
	write(1, buffer, size);
}

/**
 * _memcopy - a function that add a second string to first string
 * @dest: a destination string
 * @src: a source string
 * @n: the length of current buffer
 * Return: return a pointer to string
 */
char *_memcopy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i + n] = src[i];
	return (dest);
}

/**
 * ctos - a function change a single character to a string
 * @c: a charater
 *
 * Return: return a pointer to string
 */
char *ctos(char c)
{
	static char str[2];

	str[0] = c;
	str[1] = '\0';
	return (str);
}
