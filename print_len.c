#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * print_char - prints char
 * @args: arguments
 * @count: the number of chars
 */
void print_char(va_list args, int *count)
{
	int c = va_arg(args, int);

	printf("%c", c);
	(*count)++;
}

/**
 * print_string - prints string
 * @args: argument string
 * @count: the number of chars in string
 */
void print_string(va_list args, int *count)
{
	char *s = va_arg(args, char *);

	if (s == NULL)
	{
		printf("(null)");
		(*count) += 6;
	}
	else
	{
		printf("%s", s);
		(*count) += strlen(s);
	}
}

/**
 * print_int - prints integer
 * @args: argument integer
 * @count: the number of chars in int
 */
void print_int(va_list args, int *count)
{
	int arg = va_arg(args, int);

	printf("%d", arg);
	(*count) += count_int_digits(arg);
}

/**
 * print_percent - prints percent sign
 * @args: argument
 * @count: the number of chars printed
 */
void print_percent(__attribute__ ((unused)) va_list args, int *count)
{
	printf("%%");
	(*count)++;
}

/**
 * _printf - prints the number of chars printed
 * @format: a character string
 * @...: arguments
 * Return: string length
*/

int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;

	FormatSpec formats[] = {
		{'c', print_char},
		{'s', print_string},
		{'d', print_int},
		{'i', print_int},
		{'%', print_percent},
		{'\0', NULL}
	};
	va_start(args, format);
	if (format == NULL)
		return (0);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			char specifier = format[++i];
			int j = 0;

			while (formats[j].specifier != '\0')
			{
				if (formats[j].specifier == specifier)
				{
					formats[j].conversion_func(args, &count);
					break;
				}
				j++;
			}
		}
		else
		{
			printf("%c", format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
