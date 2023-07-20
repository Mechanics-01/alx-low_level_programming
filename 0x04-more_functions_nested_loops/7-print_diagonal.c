#include "main.h"
/**
 * print_diagonal - Draws a daigonal line on terminal
 * @n: target variable
 *
 * Return: Nothing
 */

void print_diagonal(int n)
{
	int ch, i;

	if (n > 0)
	{
		for (ch = 0; ch < n; ch++)
		{
			for (i = 0; i < ch; i++)
				_putchar(' ');
			_putchar('\\');
			_putchar('\n');
		}
	}
	_putchar(10);
}
