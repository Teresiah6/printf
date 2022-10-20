#include "main.h"
/**
 * _printf - entry point
 * @format: character string
 * Return: int
 */
int _printf(const char *format, ...)
{
	int (*ptrfunc)(va_list);
	const char *p;
	va_list args;

	registered int count = 0;


	va_start(args, format);

	if(!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if(format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count +=_putchar('%');
				continue;
			}
			ptrfunc = get_print(*p);
			count += (ptrfunc)
				? ptrfunc(args)
				: _printf("%%%c", *p);
		}
		else
		{
			count += _putchar(*p);
		}
	}
	_putchar(-1);
	va_end(args);
	return (count);
}