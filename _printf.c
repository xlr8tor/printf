#include "main.h"
/**
 * print_buffer - prints the contents of a buffer
 * @buffer: an array of chars
 * @buffer_index: current index in buffer
 */
void print_buffer(char *buffer, int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, buffer, *buffer_index);
	*buffer_index = 0;
}

/**
 * _printf - produces output according to a format
 * @format: character string to print
 * @...: optional arguments
 *
 * Return: length of the string
 */
int _printf(const char *format, ...)
{
	int i, buffer_index = 0, length = 0, printed = 0;
	int flags, width, precision, size;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFFER_SIZE)
				print_buffer(buffer, &buffer_index);
			length++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, args, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			length += printed;
		}
	}

	print_buffer(buffer, &buffer_index);
	va_end(args);
	return (length);
}
