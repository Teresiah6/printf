#include "main.h"
#include <unistd.h>
/**
 * _putchar - print char 
 * @c: character
 * Return: int
 */
int _putchar(char c)
{
	static char buff [1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buff, i);
		i = 0; 
	}
	if  ( c != -1)
	{
		buf[i] = c;
		i++;
	}

	return (1);
}
/**
 * _puts - print string
 * @str: string
 * Return: int 
 */
int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[1]);

	return (i);
}
