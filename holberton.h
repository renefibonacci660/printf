#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
#define BUFFERSIZE 1024
/**
 * struct ArgTypes - data structure for argument
 * @car: pointer to format charater
 * @fn: function pointer to argument
 */
typedef struct ArgTypes
{
	char *car;
	char *(*fn)();
} Arg_Types;

int _printf(const char *format, ...);
char *(*get_arg_type(char s))(va_list);
char *found_percent();
char *found_char(va_list c);
char *found_string(va_list *s);
char *found_int(va_list num);
char *found_unsigned(va_list usign);
char *found_nothing(char);
char *found_octal(va_list octal);
char *found_hex(va_list hex);
int _strlen(char *s);
char *ctos(char c);
int _putchar(char c);
void _puts(char *str, int size);

#endif /* HOLBERTON_H */
