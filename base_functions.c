#include "main.h"
#include <stdio.h>
int hex_check(int, char);

/**
* print_binary - Convert a number from base 10 to binary
* @list: List of arguments passed to the function
*
* Return: The length of the number printed
*/
int print_binary(va_list list)
{
unsigned int num;
int len, i;
char *str, *rev_str;

num = va_arg(list, unsigned int);
if (num == 0)
return (_write_char('0'));

if (num < 1)
return (-1);

len = base_len(num, 2);
str = malloc(sizeof(char) * (len + 1));
if (str == NULL)
return (-1);

for (i = 0; num > 0; i++)
{
str[i] = (num % 2 == 0) ? '0' : '1';
num = num / 2;
}
str[i] = '\0';

rev_str = rev_string(str);
if (rev_str == NULL)
{
free(str);
return (-1);
}

write_base(rev_str);
free(str);
free(rev_str);
return (len);
}


/**
* print_octal - Converts a number from base 10 to octal
* @list: List of arguments passed to this function
* Return: Number of symbols printed to stdout
*/
int print_octal(va_list list)
{
unsigned int num;
int len;
char *octal_rep;
char *rev_str;

num = va_arg(list, unsigned int);

if (num == 0)
return (_write_char('0'));

len = base_len(num, 8);
octal_rep = malloc(sizeof(char) * len + 1);
if (octal_rep == NULL)
return (-1);

for (len = 0; num > 0; len++)
{
octal_rep[len] = (num % 8) + '0';
num /= 8;
}
octal_rep[len] = '\0';

rev_str = rev_string(octal_rep);
if (rev_str == NULL)
{
free(octal_rep);
return (-1);
}

write_base(rev_str);
free(octal_rep);
free(rev_str);
return (len);
}

/**
* print_hex - Prints a representation of a decimal number on base16 lowercase
* @list: List of the arguments passed to the function
* Return: Number of characters printed
*/
int print_hex(va_list list)
{
unsigned int num;
int len;
int rem_num;
char *hex_rep;
char *rev_hex;

num = va_arg(list, unsigned int);

if (num == 0)
return (_write_char('0'));
if (num < 1)
return (-1);
len = base_len(num, 16);
hex_rep = malloc(sizeof(char) * len + 1);
if (hex_rep == NULL)
return (-1);
for (len = 0; num > 0; len++)
{
rem_num = num % 16;
if (rem_num > 9)
{
rem_num = hex_check(rem_num, 'x');
hex_rep[len] = rem_num;
}
else
hex_rep[len] = rem_num + 48;
num = num / 16;
}
hex_rep[len] = '\0';
rev_hex = rev_string(hex_rep);
if (rev_hex == NULL)
return (-1);
write_base(rev_hex);
free(hex_rep);
free(rev_hex);
return (len);
}


/**
* print_heX - Prints a representation of a decimal number on base16 Uppercase
* @list: List of the arguments passed to the function
* Return: Number of characters printed
*/
int print_heX(va_list list)
{
unsigned int num;
int len;
int rem_num;
char *hex_rep;
char *rev_hex;

num = va_arg(list, unsigned int);

if (num == 0)
return (_write_char('0'));
if (num < 1)
return (-1);
len = base_len(num, 16);
hex_rep = malloc(sizeof(char) * len + 1);
if (hex_rep == NULL)
return (-1);
for (len = 0; num > 0; len++)
{
rem_num = num % 16;
if (rem_num > 9)
{
rem_num = hex_check(rem_num, 'X');
hex_rep[len] = rem_num;
}
else
hex_rep[len] = rem_num + 48;
num = num / 16;
}
hex_rep[len] = '\0';
rev_hex = rev_string(hex_rep);
if (rev_hex == NULL)
return (-1);
write_base(rev_hex);
free(hex_rep);
free(rev_hex);
return (len);
}
