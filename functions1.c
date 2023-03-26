#include "main.h"
/**
 * print_binary - prints binary equivalent of decimal number
 * @args: list of arguments
 * @buffer: array of chars
 *
 * Return: length of string printed
 */

int print_binary(va_list args, char *buffer)
{
	unsigned int lmb, i, sum, count;
	unsigned int number;
	unsigned int binary[32];

	UNUSED(buffer);

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
 * print_int - prints an integer
 * @args: list of arguments
 * @buffer: array of chars
 *
 * Return: length of string printed
 */
int print_int(va_list args, char *buffer)
{
	int i = BUFFER_SIZE - 2;
	long int number = va_arg(args, long int);

	UNUSED(buffer);

	if (number == 0)
		return (1);
	i++;
	return (1);
}

/**
 * print_unsigned - prints an integer
 * @args: list of arguments
 * @buffer: array of chars
 *
 * Return: length of string printed
 */
int print_unsigned(va_list args, char *buffer)
{
	int i = BUFFER_SIZE - 2;
	int length;
	unsigned long int number = va_arg(args, unsigned long int);

	if (number == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;
	length = BUFFER_SIZE - i - 1;
	return (write(1, &buffer[i], length));

}

/**
 * print_octal = prints an integer in base 8
 * @args: list of arguments
 * @buffer: array of chars
 *
 * Return: length of string
 */
int print_octal(va_list args, char *buffer)
{
	int i = BUFFER_SIZE - 2;
	int length;
	unsigned long int number = va_arg(args, unsigned long int);

	UNUSED(buffer);

	if (number == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';

	while (number > 0)
	{
		buffer[i--] = (number % 8) + '0';
		number /= 8;
	}

	i++;
	length = BUFFER_SIZE - i - 1;
	return (write(1, &buffer[i], length));
}
