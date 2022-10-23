#include "main.h"

/**
 * _printf - prints like printf
 * @format: the format specifier and or normal string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, j = 0, buff_count = 0, prev_buff_count = 0;

	char buffer[1024];

	va_list vars;

	formspec fspec[] = {{'s', prString}, {'c', prChar}, {'X', prX},
		{'u', prUint}, {'o', prOct}, {'x', prHex}, {'b', prBinary},
		{'%', prPercent}, {'d', prInt}, {'i', prInt}, {'S', prS},
		{'r', prReverse}, {'R', prRot}, {'p', prP}, {'\0', NULL}
	};
	va_start(vars, format);
	if (!format)
		return (-1);

	while (format && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++, prev_buff_count = buff_count;
			for (j = 0; fspec[j].type != '\0'; j++)
			{
				if (fspec[j].type == '\0')
					break;
				if (format[i] == fspec[j].type)
				{
					buff_count = fspec[j].func(buffer, vars, buff_count);
					break;
				}
			}
			if (buff_count == prev_buff_count && format[i])
				i--, buffer[buff_count] = format[i], buff_count++;
		}
		else
			buffer[buff_count] = format[i], buff_count++;
		i++;
	}
	va_end(vars);
	buffer[buff_count] = '\0';
	print_buff(buffer, buff_count);
	return (buff_count);
}
