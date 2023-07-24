#include "main.h"
/**
 * swap_int - swaps the values of integers
 * @a: target value to be swapped
 * @b: Second target value
 *
 * Return: void
 */

void swap_int(int *a, int *b)
{
	int c = 0;

	c = *a;
	*a = *b;
	*b = c;
}
