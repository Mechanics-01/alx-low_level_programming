#include "main.h"

/**
 * binary_to_uint - converts a binary number to an
 * to an unsigned int.
 * @b: pointer to a string of 0 and 1 chars
 * Return: the converted number or 0 or NULL
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int Integer_n = 0;
	int binary_base = 1;
	int Length = 0;
	int i;

	if (!b)
		return (0);

	/* Find the length of the binary string*/
	while (b[Length] != '\0')
		Length++;

	/* Process the binary digit from left to right*/
	for (i = Length - 1; i >= 0; i--)
	{
		if (b[i] == '1')
			Integer_n += binary_base;
		if (b[i] != '0' && b[i] != '1')
			return (0);
		binary_base *= 2;
	}
	return (Integer_n);
}
