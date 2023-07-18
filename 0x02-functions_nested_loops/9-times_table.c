#include "main.h"
/**
 * times_table - prints the 9 times table
 *
 * Return: returns nothing
 */

void times_table(void)
{
	int di, mul, res;

	for (di = 0; di <= 9; di++)
	{
		_putchar('0');
		for (mul = 1; mul <= 9; mul++)
		{
			_putchar(',');
			_putchar(' ');
			res = di * mul;
			if (res <= 9)
				_putchar(' ');
			else
				_putchar((res / 10) + '0');
			_putchar((res % 10) + '0');
		}
		_putchar('\n');
	}
}
