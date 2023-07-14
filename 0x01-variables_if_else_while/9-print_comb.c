#include <stdio.h>

/**
 * main - Prints all possible combinations of single-digit numbers.
 *
 * Return: Always 0.
 */

int main(void)
{
	int ch;

	for (ch = 0; ch <= 9; ch++)
	{
		putchar((ch % 10) + 48);
		if (ch == 9)
			continue;
		putchar(44);
		putchar(0);
	}
	putchar('\n');
	return (0);
}
