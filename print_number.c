#include "main.h"

/**
* print_number - prints a number send to this function
* @args: List of arguments
* Return: The number of arguments printed
*/
int print_number(va_list args)
{
int n = va_arg(args, int);
unsigned int num;
unsigned int div = 1;
int len = 0;

if (n < 0)
{
len += _write_char('-');
num = (unsigned int)(-n);
}
else
num = (unsigned int)n;

for (; num / div > 9; div *= 10)
{}

for (; div != 0; div /= 10)
{
len += _write_char('0' + num / div);
num %= div;
}

return (len);
}

/**
* print_unsgined_number - Prints an unsigned number
* @n: unsigned integer to be printed
* Return: The amount of numbers printed
*/
int print_unsgined_number(unsigned int n)
{
unsigned int num = n;
unsigned int div = 1;
int len = 0;

for (; num / div > 9; div *= 10)
{}

for (; div != 0; div /= 10)
{
len += _write_char('0' + num / div);
num %= div;
}

return (len);
}
