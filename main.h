#ifndef MAIN_H
#define MAIN_H


/**
 * flag - typedef struct
 * @plus: for '+'
 * @space: flag ' '
 * @hash: for '#'
 */
typedef struct flag
{
	int plus;
	int space;
	int hash;
}flag_t;

int _printf(const char *format, ...);
int _putchar(char c);
int (*get_print(char s))(va_list, flag_t *);
int get_flag(char s, flag_t *f);
int _puts(char *str);


#endif
