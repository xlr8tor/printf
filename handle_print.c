#include "main.h"

int handle_print(const char *format, int *buffer_index, va_list args,
char *buffer)
{

	int i, length = -1, tmp_len = 0;

	fmt_t fmt_list[] = {
		{'i', print_int}, 
		{'d', print_int},
		{'b', print_binary},
		{'u', print_unsigned},
		{'\0', NULL}};

	for (i = 0; fmt_list[i].op != '\0'; i++)
		if (format[*buffer_index] == fmt_list[i].op)
			return (fmt_list[i].fn(args, buffer));

	if (fmt_list[i].op == '\0')
	{
		if (format[*buffer_index] == '\0')
			return (length);
		tmp_len += write(1, "%%", 1);

		if (format[*buffer_index - 1] == ' ')
			tmp_len += write(1, " ", 1);
		tmp_len += write(1, &format[*buffer_index], 1);
		return (tmp_len);
	}
	return (length);
}
