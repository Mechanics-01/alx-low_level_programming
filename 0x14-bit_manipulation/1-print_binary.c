#include "main.h"

/**
 * print_binary - prints the binary representation
 * of a number.
 * @n: unsigned long int.
 * Return: no return.
 */
void print_binary(unsigned long int n)
{
	int i;
	int binary[64];
	int index = 0;

	if (n == 0)
		_putchar('0');

	while (n > 0 && index < 64)
	{
		binary[index++] = n & 1;
		n >>= 1;
	}

	for (i = index - 1; i >= 0; i--)
	{
		_putchar(binary[i] + '0');
	}
}
