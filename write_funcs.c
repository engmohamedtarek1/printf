#include "main.h"
#include <unistd.h>


/**
 * _puts - prints a string with newline
 * @str: the string to print
 * Return: number of chars printed
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Description: _putchar uses a local buffer of 1024 to call write little
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static char buffer[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buffer, i);
		i = 0;
	}
	if (c != -1)
	{
		buffer[i] = c;
		++i;
	}
	return (1);
}
