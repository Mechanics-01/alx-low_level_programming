#include "main.h"
/**
 * print_triangle - prints a triangle followed by a new line
 * @size: target size of triangle
 *
 * Return: void
 */

void print_triangle(int size)
{
	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		int ch, n;

		for (ch = 1; ch <= size; ch++)
		{
			for (n = ch; n < size; n++)
			{
				_putchar(' ');
			}
			for (n = 1; n <= ch; n++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
