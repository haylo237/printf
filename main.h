#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int format_switch(va_list args, char specifier, int *length);
int _putchar(char c);

#endif
