#include "main.h"
#include <stdio.h>

/**
 * reverser - reverse a string
 * @s: string to reverse
 * Return: pointer to reversed string
 */
char *reverser(char *s)
{
	int len, head;
	char tmp;
	char *dest;

	for (len = 0; s[len] != '\0'; len++)
	{} /* make len equal to strlen */

	dest = malloc(sizeof(char) * len + 1);

	if (dest == NULL)
		return (NULL);

	_memcpy(dest, s, len);

	for (head = 0; head < len; head++, len--)
	{/* swap first and last */
		tmp = dest[len - 1];
		dest[len - 1] = dest[head];
		dest[head] = tmp;
	}
	return (dest);
}

/**
 * b_len - calculate length of number depending on base
 * @num: number to calculate for
 * @base: base
 * Return: length of number to base base
 */
unsigned int b_len(unsigned int num, int base)
{
	unsigned int i;

	for (i = 0; num > 0; i++)
	{
		num /= base;
	}
	return (i);

}

/**
 * _memcpy - copy memory area
 * @dest: destination
 * @src: source
 * @n: number of bytes
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * tHex - adds (ASCII) of string char to buffer
 * @buff_dest: buffer
 * @str: string character
 * @buff_count: buffer index
 * Return: buffer index
 */
int tHex(char *buff_dest, char str, int buff_count)
{

	int i = 0, j, temp, t;
	char hx[2], c;

	c = str;
	t = (int)c;

	while (i < 2)
	{
		temp = t % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 55;

		hx[i] = temp;
		i++;
		t /= 16;
	}
	for (j = 1; j >= 0; j--)
	{
		buff_dest[buff_count] = hx[j];
		buff_count++;
	}

	return (buff_count);
}
