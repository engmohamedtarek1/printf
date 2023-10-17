#include "main.h"

/**
 * print_int - prints an integer
 * @l: list of arguments
 * @f: the parameters struct
 * Return: number bytes printed
 */
int print_int(va_list l, flags_t *f)
{
	int n = va_arg(l, int);
	int respond = cnt_digit(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		respond += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		respond = respond + _putchar('+');
	if (n <= 0)
		++respond;
	print_number(n);
	return (respond);
}

/**
 * print_unsigned - prints an unsigned integer
 * @l: list of arguments
 * @f: the parameters struct
 * Return: number bytes printed
 */
int print_unsigned(va_list l, flags_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = conversion(u, 10, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_number - helper function that loops through
 * @n: integer to be printed
 */
void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		print_number(n1 / 10);
	_putchar((n1 % 10) + '0');
}

/**
 * cnt_digit - returns the number of digits in an integer for _printf
 * @i: integer to evaluate
 * Return: number of digits
 */
int cnt_digit(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u = u / 10;
		++d;
	}
	return (d);
}
