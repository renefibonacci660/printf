#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * rot13 - Converts string to rot13
 * @list: string to convert
 * Return: converted string
 */
char *found_rot13(va_list *rot13)
{
	int i;
	int x;
	char *str;
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char u[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(rot13, char *);
	if (str == NULL)
		return ("(null)");
	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (str[i] == s[x])
			{
				_putchar(u[x]);
				break;
			}
		}
		if (x == 53)
			_putchar(str[i]);
	}
	return ("");
}
