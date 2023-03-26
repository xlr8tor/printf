#include "main.h"

int handle_print(const char *format, int *buffer_index, va_list args,
char *buffer, int flags, int width, int precision, int size)
{
	int i, length = -1, tmp_len = 0;
	fmt_t fmt_list[] = {
		{'i', print_int}, {'d', print_int}, {'o', print_octal},
		{'b', print_binary}, {'u', print_unsigned},
		{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'r', print_reverse},
		{'R', print_rot13string}, {'p', print_pointer},
		{'S', print_non_printable}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'\0', NULL}};

	for (i = 0; fmt_list[i].op != '\0'; i++)
		if (format[*buffer_index] == fmt_list[i].op)
			return (fmt_list[i].fn(args, buffer, flags, width,
					precision, size));

	if (fmt_list[i].op == '\0')
	{
		if (format[*buffer_index] == '\0')
			return (length);
		tmp_len += write(1, "%%", 1);

		if (format[*buffer_index - 1] == ' ')
			tmp_len += write(1, " ", 1);
		else if (width)
		{
			--(*buffer_index);
			while (format[*buffer_index] != ' '
					&& format[*buffer_index] != '%')
				--(*buffer_index);
			if (format[*buffer_index == ' '])
				--(*buffer_index);
			return (1);
		}
		tmp_len += write(1, &format[*buffer_index], 1);
		return (tmp_len);
	}
	return (length);
}
