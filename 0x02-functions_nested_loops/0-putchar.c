#include "main.h"

/**
 * main - functions prints text as output
 *
 * Return: return 0
 */

int main(void)
{
	char ch[10] = "_putchar";
	int i;

	for (i = 0; i < 8; i++)
	{
		_putchar(ch[i]);
	}
	_putchar(10);
	return (0);
}
