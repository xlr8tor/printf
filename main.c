#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
  * main - entry point
  * Return: 0
  */

int main(void)
{
	unsigned int ui;

	ui = (unsigned int)INT_MAX + 1024;

	_printf("Hello world\n");
	_printf("%b\n", 98);
	_printf("Unknown:[%r]\n");
	_printf("Unsigned:[%u]\n", ui);
	_printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	_printf("String:[%R]\n", "I am a string !");
	_printf("String:[%r]\n", "I am a string !");
	return (0);
}
