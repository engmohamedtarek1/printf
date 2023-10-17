#include "main.h"

/**
 * get_print - selects the right printing function depending on the conversion specifier passed to _printf
 * @s: the format string
 * Description: the function loops through the structs array
 * array_function[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate printing function
 *
 * Return: the number of bytes printed
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph array_function[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (array_function[i].c == s)
			return (array_function[i].f);
	return (NULL);
}
