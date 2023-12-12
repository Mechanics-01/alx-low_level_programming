#include "main.h"
/**
 * *_strcat - concatenates two strings
 * @dest: target string
 * @src: target string to be added
 *
 * Return: void
 */

char *_strcat(char *dest, char *src)
{
	int i, k = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	while (src[k] != '\0')
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
