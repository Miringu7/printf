#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int write_number(int number, int num_char_printed);
int convert_to_binary(int integer_num, int num_char_printed);

#endif
