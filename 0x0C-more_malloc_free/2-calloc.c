#include "main.h"

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: members of array
 * @size: size of each member
 * Return: void
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *array;

	if (nmemb == 0 || size == 0)
		return (NULL);

	array = malloc(nmemb * size);

	if (array == NULL)
		return (NULL);

	for (i = 0; i < nmemb; i++)
		array[i] = 0;

	return (array);
}
