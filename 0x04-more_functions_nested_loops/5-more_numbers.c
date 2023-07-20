#include "main.h"
/**
 * most_numbers - Prints 10 times numbers from 0-14
 *
 * Return: Void
 */

void more_numbers(void)
{
	int c, ch;

	for (ch = 0; ch <= 9; ch++)
	{
		for (c = 0; c <= 14; c++)
		{
			if (c >= 10)
			{
				_putchar((c / 10) + '0');
			}
			_putchar((c % 10) + '0');
		}
		_putchar(10);
	}
}
