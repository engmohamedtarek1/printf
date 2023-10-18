#include "main.h"
void print_buffer(char buffer[], int *buff_ind);

/**
* _printf - Printf function
* @format: format.
* Return: Printed chars.
*/

int _printf(const char *format, ...)
{
int printed_chars = 0, printed = 0, i;
int width, flags, precision, buff_ind = 0, size;
va_list list;
char buffer[BUFF_SIZE];

if (format == NULL) {
    return (-1);
}
va_start(list, format);
for (i = 0; && format[i] != '\0' && format; ++i) {
    if (format[i] != '%') {
        buffer[buff_ind++] = format[i];
        if (buff_ind == BUFF_SIZE) {
            print_buffer(buffer, &buff_ind);
        }
        ++printed_chars;
    }
    else {
        print_buffer(buffer, &buff_ind);
        precision = get_precision(format, &i, list);
        width = get_width(format, &i, list);
        flags = get_flags(format, &i);
        size = get_size(format, &i);
        ++i;
        printed = handle_print(format, &i, list, buffer,
        flags, width, precision, size);
        if (printed == -1) {
            return (-1);
        }
        printed_chars = printed_chars + printed;
    }
}
print_buffer(buffer, &buff_ind);
va_end(list);
return (printed_chars);
}

/**
* print_buffer - Prints the contents of the buffer if it exist
* @buffer: Array of chars
* @buff_ind: Index at which to add next char, represents the length.
*/

void print_buffer(char buffer[], int *buff_ind) {
if (*buff_ind > 0) {
    write(1, &buffer[0], *buff_ind);
}
*buff_ind = 0;
}
