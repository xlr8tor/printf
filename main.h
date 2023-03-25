#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) (void) (x)

/**
 * struct fmt - user defined type fmt
 * creates the blueprint for a format type
 * @op: operator
 * @fn: the print function
 *
 * Description: blueprint for fmt type
 */
struct fmt
{
	char op;
	int (*fn)(va_list, char[]);
};

/**
 * fmt_t - typedef for struct fmt
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
void print_buffer(char *buffer, int *buffer_index);
int handle_print(const char *fmt, int *i, va_list args, char *buffer);

/************** FUNCTIONS ***********************/
/* PRINT CHAR, STRING & PERCENTAGE */
int print_char(va_list args, char *buffer);
int print_string(va_list args, char *buffer);
int print_percent(va_list args, char *buffer);

/* PRINT NUMBERS */
int print_int(va_list args, char *buffer);
int print_binary(va_list args, char *buffer);
int print_unsigned(va_list args, char *buffer);

#endif /* MAIN_H */
