#include "main.h"

/**
 * print_hex - prints unsigned hex number in lowercase
 * @l: va_list arguments
 * @f: the parameters struct
 * Return: number bytes printed
 */
int print_hex(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = conversion(num, 16, 1);
	int cnt = 0;

	if (f->hash == 1 && str[0] != '0')
		cnt = cnt + _puts("0x");
	cnt = cnt + _puts(str);
	return (cnt);
}

/**
 * print_hex_big - prints unsigned hex number in uppercase
 * @l: va_list arguments
 * @f: the parameters struct
 * Return: number bytes printed
 */
int print_hex_big(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = conversion(num, 16, 0);
	int cnt = 0;

	if (f->hash == 1 && str[0] != '0')
		cnt = cnt + _puts("0X");
	cnt = cnt + _puts(str);
	return (cnt);
}

/**
 * print_binary - prints unsigned binary number
 * @l: va_list arguments
 * @f: the parameters struct
 * Return: number bytes printed
 */
int print_binary(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = conversion(num, 2, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_octal - prints unsigned octal number
 * @l: va_list arguments
 * @f: the parameters struct
 * 
 * Return: number bytes printed
 */
int print_octal(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str = conversion(num, 8, 0);
	int cnt = 0;

	if (f->hash == 1 && str[0] != '0')
		cnt = cnt + _putchar('0');
	cnt = cnt + _puts(str);
	return (cnt);
}
