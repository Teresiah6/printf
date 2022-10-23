#include "main.h"



/**

 * prUint - substitute %u by argument number

 * @buff_dest: buffer

 * @vars: va_list arg to change

 * @buff_count: index of dst where the u of %u is

 * Return: New index

 */

int prUint(char *buff_dest, va_list vars, int buff_count)

{

	int num = 1;

	unsigned int x;

	unsigned int number;



	number = va_arg(vars, unsigned int);



	x = number;



	while (x > 9)

	{

		num *= 10;

		x /= 10;

	}



	x = number;

	while (num > 0)

	{

		buff_dest[buff_count] = ('0' + x / num);

		x %= num;

		num /= 10;

		buff_count++;

	}



	return (buff_count);

}



/**

 * prOct - substitute %o by unsigned int argument number

 * @buff_dest: buffer

 * @vars: va_list arg to change

 * @buff_count: index of buffer where the o of %o is

 * Return: New index

 */

int prOct(char *buff_dest, va_list vars, int buff_count)

{

	unsigned int number = va_arg(vars, unsigned int);

	unsigned int num = number;

	int oct = 1;



	while (num > 7)

	{

		oct *= 8;

		num /= 8;

	}



	num = number;

	while (oct > 0)

	{

		buff_dest[buff_count] = ('0' + num / oct);

		num %= oct;

		oct /= 8;

		buff_count++;

	}



	return (buff_count);

}

/**

 * prHex - substitute %x by unsigned int argument number

 * @buff_dest: buffer

 * @vars: arguments to change

 * @buff_count: index of buffer where the o of %x is

 * Return: New index

 */

int prHex(char *buff_dest, va_list vars, int buff_count)

{

	unsigned int number = va_arg(vars, unsigned int);

	unsigned int num  = number;

	int hex = 1;



	while (num > 15)

	{

		hex *= 16;

		num /= 16;

	}



	num = number;

	while (hex > 0)

	{

		buff_dest[buff_count] = (num / hex < 9) ?

			(num / hex + '0') : ('a' + num / hex - 10);

		num %= hex;

		hex /= 16;

		buff_count++;

	}



	return (buff_count);

}

/**

 * prX - substitute %X by unsigned int argument number

 * @buff_dest: buffer

 * @vars: va_list arg to change

 * @buff_count: index of buffer where the o of %X is

 * Return: New index

 */

int prX(char *buff_dest, va_list vars, int buff_count)

{

	unsigned int number = va_arg(vars, unsigned int);

	unsigned int num = number;

	int hex = 1;



	while (num > 15)

	{

		hex *= 16;

		num /= 16;

	}



	num = number;

	while (hex > 0)

	{

		buff_dest[buff_count] = (num / hex < 9) ?

			(num / hex + '0') : ('A' + num / hex - 10);

		num %= hex;

		hex /= 16;

		buff_count++;

	}



	return (buff_count);

}
