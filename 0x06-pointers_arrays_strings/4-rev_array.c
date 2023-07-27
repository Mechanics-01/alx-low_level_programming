#include "main.h"
/**
 * reverse_array - function that rverses the content of an array of integers
 * @a: target arrays of integers
 * @n: number of elements of the array
 *
 * Return: void
 */

void reverse_array(int *a, int n)
{
	int i, b;

	i = 0;
	while (i < n)
	{
		n--;
		b = a[i];
		a[i] = a[n];
		a[n] = b;
		i++;
	}
}
