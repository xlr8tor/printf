#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) ((void) (x))

/*   SIZES   */
#define S_LONG 2
#define S_SHORT 1

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

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
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * fmt_t - typedef for struct fmt
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
void print_buffer(char *buffer, int *buffer_index);
int handle_print(const char *fmt, int *i, va_list args, char *buffer,
int flags, int width, int precision, int size);

/************** FUNCTIONS ***********************/
/* PRINT CHAR, STRING & PERCENTAGE */
int print_char(va_list args, char *buffer, int flags,
	int width, int precision, int size);
int print_string(va_list args, char *buffer, int flags,
	int width, int precision, int size);
int print_percent(va_list args, char *buffer, int flags,
	int width, int precision, int size);

/* PRINT NUMBERS */
int print_int(va_list args, char *buffer, int flags,
	int width, int precision, int size);
int print_binary(va_list args, char *buffer, int flags,
	int width, int precision, int size);
int print_unsigned(va_list args, char *buffer, int flags,
	int width, int precision, int size);

/* PRINT STRING IN REVERSE */
int print_reverse(va_list args, char *buffer, int flags,
	int width, int precision, int size);

/* PRINT ROT13STRING */
int print_rot13string(va_list args, char *buffer, int flags,
	int width, int precision, int size);

/* HANDLE OTHER SPECIFIERS */
int get_size(const char *format, int *index);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);

/* UTILS */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
