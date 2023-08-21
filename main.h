#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int process_format_specifier(va_list args, char specifier);
int print_number(int num);
int _putchar(char c);

#endif
