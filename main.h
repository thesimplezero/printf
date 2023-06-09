#ifndef PRINT_F
#define PRINT_F

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct convert - defines a structure for symbols and functions
 * @sym: The operator
 * @f: The function associated
 */
typedef struct convert
{
	char *sym;
	int (*f)(va_list);
} conver_t;

/*Main functions*/
int parser(const char *format, conver_t f_list[], va_list arg_list);
int _printf(const char *format, ...);
int _write_char(char);
int print_char(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reversed(va_list arg);
int rot13(va_list);
int unsigned_integer(va_list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_heX(va_list list);

/*Helper functions*/
unsigned int base_len(unsigned int num, int base);
char *rev_string(char *s);
void write_base(char *str);
char *_memcpy(char *dest, const char *src, unsigned int n);
int print_unsgined_number(unsigned int);
int print_number(va_list args);
int print_unsgined_number(unsigned int n);


#endif
