#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>

int _printf(const char *format, ...);

int count_int_digits(int n);

/**
 * struct fs - struct
 * @specifier: letter signifying data type
 * @conversion_func: function ptr
 * @args: arguments
 * @count: the number of chars printed
 */

/**
 * FormatSpec - typedef for struct fs
 */

typedef struct fs 
{
    char specifier;
    void (*conversion_func)(va_list args, int *count);
} FormatSpec;

#endif
