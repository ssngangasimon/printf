#include "main.h"

/************Print unsigned num****************/
/**
 * print_unsigned - prints the unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calculate the active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: the number of printed chars
 * Author: Simon Nganga & Esther Wambui
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/***********Print unsigned num in Octal notation**************/
/**
 * print_octal - print the unsigned number in Octal
 * @types: a list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calculate the active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: the number of characters printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/***********Print unsigned number in Hexadecimal notation***********/
/**
 * print_hexadecimal - print the unsigned number in Hexadecimal
 * @types: a list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calculate the active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: the number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/*********Print unsigned number in Upper Hexadecimal notation**************/
/**
 * print_hexa_upper - print the unsigned number in Upper Hexadecimal
 * @types: a list of arguments
 * @buffer: Buffer array to handle print
 * @flags:  calculate the active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * Return: the number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**********Print Hexadecimal Num in lower or UPPER**********/
/**
 * print_hexa - print a hexadecimal number in lower or UPPER
 * @types: a list of arguments
 * @map_to: Array of values to map the number
 * @buffer: Buffer array to handle print
 * @flags:  calculate the active flags
 * @flag_ch: Calculate active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 * @size: size specification
 * Return: the number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

