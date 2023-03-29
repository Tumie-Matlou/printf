#include <stdio.h>
#include "main.h"

int main()
{
int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = 0;
    char c;
    while ((c = *format++) != '\0')
    {
        if (c == '%')
        {
            switch (*format++)
            {
                case 'c':
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':
                    for (char *s = va_arg(args, char *); *s != '\0'; s++)
                    {
                        putchar(*s);
                        count++;
                    }
                    break;
                case '%':
                    putchar('%');
                    count++;
                    break;
                case 'd':
                case 'i':
                    printf("%d", va_arg(args, int));
                    count++;
                    break;
            }
        }
        else
        {
            putchar(c);
            count++;
        }
    }
    va_end(args);
    return count;
}
return 0;
}

