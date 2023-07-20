#include "main.h"
/**
 * print_numbers - Prints the numbers, from 0 to 9, followed by a new line
 *
 * Return: Nothing
 */

void print_numbers(void)
{
	int ch;

	for (ch = '0'; ch <= '9'; ch++)
		_putchar(ch);
	_putchar(10);
}
