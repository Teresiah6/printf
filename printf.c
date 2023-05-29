#include "main.h"

/**
 * _printf - prints like printf
 * @format: the format specifier and or normal string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	 va_list args;
    va_start(args, format);

    int printed_chars = 0;
    char ch;
    const char *str;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            if (*format == '%')
            {
                putchar('%');
                printed_chars++;
            }
            else if (*format == 'c')
            {
                ch = (char)va_arg(args, int);
                putchar(ch);
                printed_chars++;
            }
            else if (*format == 's')
            {
                str = va_arg(args, const char *);
                while (*str != '\0')
                {
                    putchar(*str);
                    str++;
                    printed_chars++;
                }
            }
        }
        else
        {
            putchar(*format);
            printed_chars++;
        }

        format++;
    }

    va_end(args);

    return printed_chars;
}
