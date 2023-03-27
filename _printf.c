#include "main.h"

/**
* _printf - Print formatted output to stdout.
* @format: A string containing the format specification.
*
* Return: Number of characters printed
*/
int _printf(const char *format, ...)
{
va_list args;
conver_t f_list[] = {
{"c", print_char},
{"s", print_string},
{"%", print_percent},
{"d", print_integer},
{"i", print_integer},
{"b", print_binary},
{"r", print_reversed},
{"R", rot13},
{"u", unsigned_integer},
{"o", print_octal},
{"x", print_hex},
{"X", print_heX},
{NULL, NULL}
};
int printed_chars = 0;

if (format == NULL)
return (-1);

va_start(args, format);
printed_chars = parser(format, f_list, args);
va_end(args);

return (printed_chars);
}
