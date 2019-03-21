#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>

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
/* the following are prototypes */
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
char *found_HEX(va_list HEX);
int _strlen(char *s);
int _putchar(char c);
void _puts(char *str, int size);
char *found_bin(va_list bin);
char *found_add(va_list add);
char *convert(unsigned int num, int base, int flag);
char *convert_add(unsigned long num, unsigned long base, int flag);
char *found_rot13(va_list *rot13);
char *found_unprint(va_list *unprt);
char *convert_unprt(unsigned int asc, int base);

#endif /* HOLBERTON_H */
