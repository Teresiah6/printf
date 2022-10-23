#ifndef MAIN_H

#define MAIN_H

#include <stdarg.h>

#include <stddef.h>

#include <unistd.h>

#include <stdlib.h>

/**

 * struct form - parameters

 * @type: format specifier

 * @func: function

 */

typedef struct form

{

	char type;

	int (*func)(char *, va_list, int);

} formspec;



/**

 * struct flags - struct containing flags to "turn on"

 *

 * @plus: flag for the '+' character

 * @space: flag for the ' ' character

 * @hash: flag for the '#' character

 */

typedef struct flags

{

	int plus;

	int space;

	int hash;

} flags_t;



int _putchar(char c);

int _printf(const char *format, ...);

int print_buff(char *buff, unsigned int nbuff);

int prChar(char *buff_dest, va_list vars, int buff_count);

int prString(char *buff_dest, va_list vars, int buff_count);

int prPercent(char *buff_dest, va_list vars, int buff_count);

int prInt(char *buff_dest, va_list vars, int buff_count);



int prUint(char *buff_dest, va_list arg, int buff_count);

int prOct(char *buff_dest, va_list arg, int buff_count);

int prHex(char *buff_dest, va_list vars, int buff_count);

int prX(char *buff_dest, va_list vars, int buff_count);

int get_flag(char s, flags_t *f);





int prBinary(char *buff_dest, va_list vars, int buff_count);

int prReverse(char *buff_dest, va_list vars, int buff_count);

int prRot(char *buff_dest, va_list vars, int buff_count);

int prS(char *buff_dest, va_list vars, int buff_count);

int tHex(char *buff_dest, char str, int buff_count);

int prP(char *buff_dest, va_list vars, int buff_count);

/* extra */



char *reverser(char *s);

unsigned int b_len(unsigned int num, int base);

char *_memcpy(char *dest, char *src, unsigned int n);

#endif
