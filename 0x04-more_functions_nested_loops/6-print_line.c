#include "main.h"
/**
 * print_line - draws a straight line in the terminal
 * @n: target number of times line character is printed
 *
 * Return: Nothing
 */

void print_line(int n)
{
	int ch;

	if (n > 0)
	{
		for (ch = 0; ch < n; ch++)
			_putchar(95);
	}
	_putchar(10);
}
