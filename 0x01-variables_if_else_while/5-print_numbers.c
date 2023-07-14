#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char ch, new_line;

	new_line = '\n';
	for (ch = 48; ch <= 57; ch++)
	{
		putchar(ch);
	}
	putchar(new_line);
	return (0);
}
