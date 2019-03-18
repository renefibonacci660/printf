#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
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
