#include "main.h"
/**
 * print_alphabet - function that prints the alphabtes
 * 		    in lower case, followed by a new line
 * Return: No return
 */

void print_alphabet(void)
{
	int ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		_putchar(ch);
	}
	_putchar(10);
}
