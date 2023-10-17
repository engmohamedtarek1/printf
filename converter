#include "main.h"

/**
 * conversion - converts number, function and base into string a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @lowercase: flag if hexa values need to be lowercase
 * @params: paramater struct
 *
 * Return: string
 */
char *conversion(unsigned long int number, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *pointer;

	rep = (!lowercase) ? "0123456789ABCDEF" : "0123456789abcdef";
	pointer = &buffer[49];
	*pointer = '\0';
	do {
		*--pointer = rep[number % base];
		number = number / base;
	} while (number != 0);

	return (pointer);
}
