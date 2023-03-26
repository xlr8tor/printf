#include "main.h"
/**
 * print_reverse - prints string in reverse
 * @args: list of arguments
 * @buffer: array of chars
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: length of string
 */
int print_reverse(va_list args, char *buffer,
	int flags, int width, int precision, int size)
{
	int i, count = 0;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	if (str == NULL)
	{
		UNUSED(precision);
		str = ")NULL(";
	}

	for (i = 0; str[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char c = str[i];

		write(1, &c, 1);
		count++;
	}

	return (count);
}

/**
 * print_rot13string - converts string to rot13string
 * @args: list of arguments
 * @buffer: arrays of chars
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: length of string
 */
int print_rot13string(va_list args, char *buffer,
	int flags, int width, int precision, int size)
{
	char *str = va_arg(args, char *);
	char lhs[] = "ABCDEFGHIGKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rhs[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, j, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);
	UNUSED(precision);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; lhs[j]; j++)
		{
			if (str[i] == lhs[j])
			{
				write(1, &(rhs[j]), 1);
				count++;
				break;
			}
		}
		if (!lhs[j])
		{
			write(1, &(str[i]), 1);
			count++;
		}
	}

	return (count);
}
