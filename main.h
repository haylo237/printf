#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);
int process_format_specifier(va_list args, char specifier);
int print_num(int num);
int print_str(const char *str);
int print_bin(unsigned int num);
int _putchar(char c);
int print_rev(char *s);

#endif
