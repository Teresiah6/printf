#include "main.h"

/**

 * prChar - prints  a char

 * @vars: list of argument

 * @buff_dest: buffer

 * @buff_count: index of the buffer pointer

 *

 * Return: buffer index

*/



int prChar(char *buff_dest, va_list vars, int buff_count)

{

	char c = va_arg(vars, int);



	buff_dest[buff_count] = c;

	return (++buff_count);

}



/**

 * prPercent - prints percentage

 * @vars: list of arguments

 * @buff_dest: buffer

 * @buff_count: index of the buffer pointer

 * Return: buffer index

 */

int prPercent(char *buff_dest, va_list vars, int buff_count)

{

	char c = va_arg(vars, int);



	c = '%';



	buff_dest[buff_count] = c;



	return (++buff_count);

}



/**

 * prString - prints a string

 * @vars: list of arguments

 * @buff_dest: buffer

 * @buff_count: index of the buffer pointer

 * Return: Number of chars printed

 */

int prString(char *buff_dest, va_list vars, int buff_count)

{

	char *str;

	int i = 0;



	str = va_arg(vars, char *);

	if (str == NULL)

		str = "(null)";

	if (str[0] == '\0')

	{

		buff_dest[buff_count] = '\0';

		buff_count++;

	}



	while (str[i] != '\0')

	{

		buff_dest[buff_count] = str[i];

		i++;

		buff_count++;

	}

	return (buff_count);

}

/**

 * prInt - prints ints

 * @vars: list of arguments

 * @buff_dest: buffer

 * @buff_count: index of the buffer pointer

 * Return: Number of digits printed

 */

int prInt(char *buff_dest, va_list vars, int buff_count)

{

	int n;

	int divisor;



	n = va_arg(vars, int);

	divisor = 1;



	if (n < 0)

	{

		buff_dest[buff_count] = '-';

		buff_count++;

		n *= -1;

	}



	for (; n / divisor > 9; )

		divisor *= 10;

	for (; divisor != 0; )

	{

		buff_dest[buff_count] = ((n / divisor) + '0');

		buff_count++;

		n = n % divisor;

		divisor /= 10;

	}



	return (buff_count);

}
