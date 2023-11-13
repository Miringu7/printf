#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int power(int base, int exponent);
unsigned int unsigned_power(unsigned int base, unsigned int exponent);
int _printf(const char *format, ...);
int write_number(int number, int num_char_printed);
int convert_to_binary(int integer_num, int num_char_printed);
int write_unsigned_number(unsigned int number, int num_char_printed);
int greater_than_zero(int integer_num, int num_char_printed);
int write_octal_num(int number, int num_char_printed);
int write_hex_num(int unsigned_hex_num, int num_char_printed);
int write_HEX_num(int unsigned_HEX_num, int num_char_printed);

#endif
