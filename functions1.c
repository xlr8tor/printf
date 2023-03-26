#include "main.h"
/**
 * print_binary - prints binary equivalent of decimal number
 * @args: list of arguments
 * @buffer: array of chars
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: length of string printed
 */

int print_binary(va_list args, char *buffer,
	int flags, int width, int precision, int size)
{
	unsigned int lmb, i, sum, count;
	unsigned int number;
	unsigned int binary[32];

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	number = va_arg(args, unsigned int);

	lmb = 2147483648;
	binary[0] = number / lmb;

	for (i = 1; i < 32; i++)
	{
		lmb /= 2;
		binary[i] = (number / lmb) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += binary[i];
		if (sum || i == 31)
		{
			char c = '0' + binary[i];

			write(1, &c, 1);
			count++;
		}
	}

	return (count);
}

/**
 * print_unsigned - prints an integer
 * @args: list of arguments
 * @buffer: array of chars
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: length of string printed
 */
int print_unsigned(va_list args, char *buffer,
	int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));

}

/**
 * print_octal - prints an integer in base 8
 * @args: list of arguments
 * @buffer: array of chars
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: length of string
 */
int print_octal(va_list args, char *buffer,
	int flags, int width, int precision, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);
	unsigned long int init_num = number;

	UNUSED(width);

	number = convert_size_unsgnd(number, size);

	if (number == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 8) + '0';
		number /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
