#include "main.h"

/**
 * _strdup - creates a duplicate of a pointer to a string
 * and returns it
 * @str: string to duplicate
 * Return: char pointer
 */

char *_strdup(char *str)
{
	char *str_dup;
	unsigned int size = 0;
	unsigned int i = 0;

	if (str == NULL)
		return (NULL);
	
	for (i = 0; str[i] != '\0'; i++)
		;
	size = i;

	str_dup = malloc(sizeof(char) * size);
	if (str_dup == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		str_dup[i] = str[i];
	str_dup[i] = '\0';

	return (str_dup);
}
