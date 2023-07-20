#include "main.h"
/**
 * print_square - Prints a square followed by a new line
 * @size: target of the square size
 *
 * Return: Void
 */

void print_square(int size)
{
	int ch, i;

	if (size > 0)
	{
		for (ch = 0; ch < size; ch++)
		{
			for (i = 0; i < size; i++)
				_putchar('#');
			_putchar(10);
		}
	}
	else
		_putchar(10);
}
