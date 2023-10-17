#include "main.h"


/**
 * print_rev - prints string in reverse
 * @l: argument from _printf
 * @f: the parameters struct
 * @ap: string
 * Return: number bytes printed
 */
int print_rev(va_list l, flags_t *f)
{
	int i = 0, j;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
		s = "(null)";

	while (s[i])
		++i;

	for (j = i - 1; j >= 0; j--)
		_putchar(s[j]);

	return (i);
}

/**
 * print_rot13 - prints string in rot13
 * @l: list of arguments
 * @ap: string
 * @f: the parameters struct
 * Return: number bytes printed
 */
int print_rot13(va_list l, flags_t *f)
{
	int i, j;
	char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *s = va_arg(l, char *);

	(void)f;
	for (j = 0; s[j]; j++)
	{
		if (s[j] > 'z' || (s[j] < 'a' && s[j] > 'Z') || s[j] < 'A'){
			_putchar(s[j]);
		}else
		{
			for (i = 0; i <= 52; i++)

			{
				if (s[j] == rot13[i]) {
					_putchar(ROT13[i]);
				}
			}
		}
	}

	return (j);
}

/**
* print_percent - prints a percent
* @l: va_list arguments from _printf
* @f: pointer to the struct flags in which we turn the flags on
* Return: number bytes printed
*/
int print_percent(va_list l, flags_t *f)
{
	(void)l;
	(void)f;
	return (_putchar( '%' ));
}

/**
* print_bigS - Non printable characters
* value in hexadecimal (upper case - always 2 characters)
* @l: list of arguments
* @f: the parameters struct
* Return: number bytes printed
*/
int print_bigS(va_list l, flags_t *f)
{
	int i, cnt = 0;
	char *respond;
	char *s = va_arg(l, char *);

	(void)f;
	if (!s)
	{
		return (_puts("(null)"));
	}
	for (i = 0; s[i]; i++)
	{
		if (s[i] > 0 && (s[i] >= 127 || s[i] < 32))
		{
			_puts("\\x");
			cnt = cnt + 2;
			respond = conversion(s[i], 16, 0);
			if (!respond[1])
				cnt = cnt + _putchar('0');
			cnt += _puts(respond);
		}
		else
			cnt = cnt + _putchar(s[i]);
	}
	return (cnt);
}
