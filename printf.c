#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - printf function
 * @format: the format string
 * Description: this function will call the get_print() function that
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int (*pointer_function)(va_list, flags_t *);
	const char *pointer;
	va_list args;
	flags_t flags = {0, 0, 0};

	register int cnt = 0;

	va_start(args, format);

	if (format[1] == ' ' && format[0] == '%' && !format[2])
		return (-1);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	for (pointer = format; *pointer; pointer++)
	{
		if (*pointer == '%')
		{
			++pointer;
			if (*pointer == '%')
			{
				cnt = cnt + _putchar('%');
				continue;
			}
			while (get_flag(*pointer, &flags))
				pointer++;
			pointer_function = get_print(*pointer);
			cnt = cnt + pointer_function ? pointer_function(args, &flags) : _printf("%%%c", *pointer);
		} else
			cnt = cnt + _putchar(*pointer);
	}
	_putchar(-1);
	va_end(args);
	return (cnt);

}
