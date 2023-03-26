#include "main.h"

/**
 * get_size - casts argument to specified size
 * @format: format string
 * @index: current index in format string
 *
 * Return: size
 */
int get_size(const char *format, int *index)
{
	int curr_index = *index + 1;
	int size = 0;

	if (format[curr_index] == 'l')
		size = S_LONG;
	else if (format[curr_index] == 'h')
		size = S_SHORT;

	if (size == 0)
		*index = curr_index - 1;
	else
		*index = curr_index;

	return (size);
}
