#include "main.h"
/**
 * print_alphabet_x10 - function that prints the alphabtes
 * in lower case, followed by a new line 10 times
 * Return: No return
 */

void print_alphabet_x10(void)
{
	int ch;
	int i = 0;

	for (i = 0; i < 10; i++)
	{
		for (ch = 'a'; ch <= 'z'; ch++)
		{
			_putchar(ch);
		}
	_putchar(10);
	}
}
