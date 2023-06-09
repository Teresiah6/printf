#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * _printf - function to print format
 * @format: list of arguments to printing
 * Return: Number of characters to printing
 */

int _printf(const char *format, ...)
{
	va_list args;

	int count = 0;

	char buffer[BUFFER_SIZE];

	int buffer_index = 0;

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
						if (buffer_index < BUFFER_SIZE - 1)
                    {
                        buffer[buffer_index++] = c;
                    }
						count++;
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char*);
						while (*str != '\0')
						{
							 if (buffer_index < BUFFER_SIZE - 1)
                        {
                            buffer[buffer_index++] = *str;
                        }
							count++;
							str++;
						}
						break;
					}
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);
						int i;
						int digits[10];
						int num_digits = 0;

						if (num < 0) {
							putchar('-');
							count++;
							num = -num;
						}

					for (i = 0; num > 0; i++) {
						digits[i] = num % 10;
						num /= 10;
						num_digits++;
					}
					for (i = num_digits - 1; i >= 0; i--) {
						putchar(digits[i] + '0');
						count++;
					}
					break;


					}
				 case 'b':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);

                    while (mask > 0)
                    {
                        putchar((num & mask) ? '1' : '0');
                        count++;
                        mask >>= 1;
                    }
                    break;
                }
		 case 'u':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%u", num);
                    count++;
                    break;
                }
                case 'o':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%o", num);
                    count++;
                    break;
                }
                case 'x':
               {
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%x", num);
                    count++;
                    break;
                }
                case 'X':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    printf("%X", num);
                    count++;
                    break;
                }
				case '%':
					{
						  if (buffer_index < BUFFER_SIZE - 1)
                    {
                        buffer[buffer_index++] = '%';
                  }
						count++;
						break;
					}
			}
		}
		else
		{
			 if (buffer_index < BUFFER_SIZE - 1)
            {
                buffer[buffer_index++] = *format;
            }
			count++;
		}
		format++;
		
		if (buffer_index >= BUFFER_SIZE - 1)
        {
            write(STDOUT_FILENO, buffer, buffer_index);
            buffer_index = 0;
        }
	}

	 if (buffer_index > 0)
    {
        write(STDOUT_FILENO, buffer, buffer_index);
    }


	va_end(args);
	return (count);
}
