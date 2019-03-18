#include "holberton.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * get_arg_type - a function that gets function pointer upon argument type
 * @s: char s after % sign
 *
 * Return: return a pointer to next argument as string
 */

char *(*get_arg_type(char s))(va_list)
{
	int i;

	Arg_Types arg_types[] = {
		{"c", found_char},
		{"s", found_string},
		{"%", found_percent},
		{NULL, NULL}
	};
	for (i = 0; arg_types[i].car; i++)
	{
		if (s == *arg_types[i].car)
			return (arg_types[i].fn);
	}
	return (NULL);
}
