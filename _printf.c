#include "main.h"

#include <stdarg.h>



/**

 * _printf - formatted output conversion and print data.

 * @format: input string.

 * check_format - checks if there is a valid format specifier

 * @format: possible valid format specifier

 *

 * Return: number of chars printed.

 * Return: pointer to valid function or NULL

 */



int (*check_format(const char *format))(va_list)

{

	int i = 0;

	print_t p[] = {

		{"c", print_c},

		{"s", print_s},

		{NULL, NULL}

	};



	for (; p[i].t != NULL; i++)

	{

		if (*(p[i].t) == *format)

			break;

	}

	return (p[i].f);

}



/**

 * _printf - function to print format

 * @format: list of arguments to printing

 * Return: Number of characters to printing

 */



int _printf(const char *format, ...)

{

	unsigned int i = 0, len = 0, ibuf = 0;

	va_list arguments;

	int (*function)(va_list, char *, unsigned int);

	char *buffer;

	va_list ap;

	int (*f)(va_list);

	unsigned int i = 0, counter = 0;



	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);

	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))

	if (format == NULL)

		return (-1);

	if (!format[i])

		return (0);

	for (i = 0; format && format[i]; i++)



	va_start(ap, format);

	while (format && format[i])

	{

		if (format[i] == '%')

		if (format[i] != '%')

		{

			if (format[i + 1] == '\0')

			_putchar(format[i]);

			counter++;

			i++;

			continue;

		}

		else

		{

			if (format[i + 1] == '%')

			{

				print_buf(buffer, ibuf), free(buffer), va_end(arguments);

				return (-1);

				_putchar('%');

				counter++;

				i += 2;

				continue;

			}

			else

			{

				function = get_print_func(format, i + 1);

				if (function == NULL)

				{

					if (format[i + 1] == ' ' && !format[i + 2])

						return (-1);

					handl_buf(buffer, format[i], ibuf), len++, i--;

				}

				else

				{

					len += function(arguments, buffer, ibuf);

					i += ev_print_func(format, i + 1);

				}

			} i++;

				f = check_format(&format[i + 1]);

				if (f == NULL)

					return (-1);

				i += 2;

				counter += f(ap);

				continue;

			}

		}

		else

			handl_buf(buffer, format[i], ibuf), len++;

		for (ibuf = len; ibuf > 1024; ibuf -= 1024)

			;

		i++;

	}

	print_buf(buffer, ibuf), free(buffer), va_end(arguments);

	return (len);

}			

	va_end(ap);

	return (counter);

}
