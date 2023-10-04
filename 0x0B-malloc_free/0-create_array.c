#include "main.h"

/**
 * create_array - creates an array of chars and initialises
 * it with a specific character
 * @size: size of the array
 * @c: initialise with character c
 * Return: char pointer
 */

char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);
	array = (char *)malloc(sizeof(char) * size);

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
