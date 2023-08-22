#ifndef MAIN_H
#define MAIN_H
#define INT_MIN -2147483648
#define INT_MAX 2147483647

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int process_format_specifier(va_list args, char specifier);
int print_num(int num);
int print_str(const char *str);
int print_bin(unsigned int num);
int _putchar(char c);

#endif
