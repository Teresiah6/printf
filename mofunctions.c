#include "main.h"

/**
 * prBinary - convert a number to binary and add to buffer
 * @buff_dest: buffer
 * @buff_count: index of buffer pointer
 * @vars: list of main arguments
 * Return: buffer index
 */
int prBinary(char *buff_dest, va_list vars, int buff_count)
{
	unsigned int num;
	int i, len;
	char *str, *rev_str;

	num = va_arg(vars, unsigned int);
	if (num == 0)
	{
		buff_dest[buff_count] = (0 + '0');
		buff_count++;
		return (buff_count);
	}
	if (num < 1)
		return (-1);

	len = b_len(num, 2);
	str = malloc(sizeof(char) * len + 1);

	if (str == NULL)
		return (-1);

	for (i = 0; num > 0; i++)
	{
		if (num % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		num /= 2;
	}
	str[i] = '\0';
	rev_str = reverser(str);

	if (rev_str == NULL)
		return (-1);

	for (i = 0; rev_str[i] != '\0'; i++)
	{/* add to buffer */
		buff_dest[buff_count] = (rev_str[i]);
		buff_count++;
	}

	free(str);
	free(rev_str);
	return (buff_count);
}

/**
 * prReverse - adds reversed string to buffer
 * @buff_dest: buffer
 * @buff_count: index of buffer pointer
 * @vars: list of main arguments
 * Return: buffer index
 */
int prReverse(char *buff_dest, va_list vars, int buff_count)
{
	int len;
	char *str, *ptr;

	str = va_arg(vars, char *);
	if (str == NULL)
		return (-1);

	ptr = reverser(str);
	if (ptr == NULL)
		return (-1);

	for (len = 0; ptr[len] != '\0'; len++)
	{
		buff_dest[buff_count] = ptr[len];
		buff_count++;
	}
	free(ptr);
	return (buff_count);

}

/**
 * prRot - adds rot9 strinig to buffer
 * @buff_dest: buffer
 * @buff_count: index of buffer pointer
 * @vars: list of main arguments
 * Return: buffer index
 */
int prRot(char *buff_dest, va_list vars, int buff_count)
{
	int i, x;
	char *str;

	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char r[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(vars, char *);

	if (str == NULL)
		return (-1);

	for (i = 0; str[i] != '\0'; i++)
	{
		for (x = 0; x <= 52; x++)
		{
			if (str[i] == s[x])
			{
				buff_dest[buff_count] = r[x];
				buff_count++;
				break;
			}
		}
		if (x == 53)
		{
			buff_dest[buff_count] = str[i];
			buff_count++;
		}
	}
	return (buff_count);
}

/**
 * prS - adds (ASCII) string to buffer
 * @buff_dest: buffer
 * @buff_count: index of buffer pointer
 * @vars: list of main arguments
 * Return: buffer index
 */
int prS(char *buff_dest, va_list vars, int buff_count)
{
	char *str;
	char hx;

	int i = 0;

	str = va_arg(vars, char *);

	if (str == NULL)
		str = "(null)";

	if (str[0] == '\0')
	{
		buff_dest[buff_count] = '\0';
		buff_count++;
		/*return (buff_count);*/
	}

	while (str[i] != '\0')
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			hx = str[i];
			buff_dest[buff_count] = 92;
			buff_dest[buff_count + 1] = 'x';
			buff_count += 2;
			buff_count = tHex(buff_dest, hx, buff_count);
			i++;

			continue;
		}
		else
		{
			buff_dest[buff_count] = str[i];
			i++;
			buff_count++;
		}
	}
	return (buff_count);
}

/**
 * prP - adds address string to buffer
 * @buff_dest: buffer
 * @buff_count: index of buffer pointer
 * @vars: list of main arguments
 * Return: buffer index
 */
int prP(char *buff_dest, va_list vars, int buff_count)
{
	int i = 0;
	char *str = va_arg(vars, char *);

	while (str[i] != '\0')
	{
		buff_dest[buff_count] = str[i];
		i++;
		buff_count++;
	}
	return (buff_count);
}
