#include "main.h"
/**
 * *_strncat - concatenates two strings till n
 * @dest: target string
 * @src: target string to be added
 * @n: Required number of bytes
 *
 * Return: void
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, k = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	while (src[k] != '\0' && k < n)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
