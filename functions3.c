#include "main.h"
/**
 * print_reverse - prints string in reverse
 * @args: list of arguments
 * @buffer: array of chars
 *
 * Return: length of string
 */
int print_reverse(va_list args, char *buffer)
{
	int i, count = 0;
	char *str = va_arg(args, char *);

	UNUSED(buffer);

	if (str == NULL)
	{
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
 *
 * Return: length of string
 */
int print_rot13string(va_list args, char *buffer)
{
	char *str = va_arg(args, char *);
	char lhs[] = "ABCDEFGHIGKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rhs[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i, j, count = 0;

	UNUSED(buffer);

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
