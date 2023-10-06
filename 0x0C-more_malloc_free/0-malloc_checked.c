#include "main.h"

/**
 * malloc_checked - allocates memory using malloc
 * @b: size of required bytes
 * Return: pointer to allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *array;

	array = malloc(b);
	if (array == NULL)
		exit(98);

	return (array);
}
