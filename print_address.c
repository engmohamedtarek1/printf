#include "main.h"

/**
 * print_address - prints a range of char addresses
 * @l: va_list arguments
 * @f: pointer to the struct flags that determines
 * Return: number bytes printed
 */
int print_address(va_list l, flags_t *f)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int cnt = 0;

	(void)f;

	if (!p)
		return (_puts("(nil)"));
	str = conversion(p, 16, 1);
	cnt = cnt + _puts("0x");
	cnt = cnt + _puts(str);
	return (cnt);
}
