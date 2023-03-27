#include "main.h"

/**
* print_reversed - Calls a function to reverse and print a string
* @arg: Argument passed to the function
* Return: The amount of characters printed
*/
int print_reversed(va_list arg)
{
char *str, *reversed_str;
int len;

str = va_arg(arg, char *);
if (str == NULL)
return (-1);

reversed_str = rev_string(str);
if (reversed_str == NULL)
return (-1);

for (len = 0; reversed_str[len] != '\0'; len++)
_write_char(reversed_str[len]);

free(reversed_str);
return (len);
}

/**
* rot13 - Converts string to rot13
* @list: string to convert
* Return: converted string
*/
int rot13(va_list list)
{
char *str;
const char *alpha_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *alpha_lower = "abcdefghijklmnopqrstuvwxyz";
const char *rot13_upper = "NOPQRSTUVWXYZABCDEFGHIJKLM";
const char *rot13_lower = "nopqrstuvwxyzabcdefghijklm";
int i, j, len = 0;

str = va_arg(list, char *);
if (str == NULL)
return (-1);

for (i = 0; str[i] != '\0'; i++)
{
for (j = 0; alpha_upper[j] != '\0'; j++)
{
if (str[i] == alpha_upper[j])
{
len += _write_char(rot13_upper[j]);
break;
}
}
for (j = 0; alpha_lower[j] != '\0'; j++)
{
if (str[i] == alpha_lower[j])
{
len += _write_char(rot13_lower[j]);
break;
}
}
if (alpha_upper[j] == '\0' && alpha_lower[j] == '\0')
len += _write_char(str[i]);
}
return (len);
}
