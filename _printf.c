#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - function to print format
 * @format: list of arguments to printing
 * Return: Number of characters to printing
 */

int _printf(const char *format, ...)
{
	va_list args;

	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char c = (char)va_arg(args, int);
						putchar(c);
						count++;
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char*);
						while (*str != '\0')
						{
							putchar(*str);
							count++;
							str++;
						}
						break;
					}
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);
						printf("%d", num);
						count++;
						break;
					}	
				case '%':
					{
						putchar('%');
						count++;
						break;
					}
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
