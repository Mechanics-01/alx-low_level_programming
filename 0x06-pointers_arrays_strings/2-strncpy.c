#include "main.h"
/**
 * *_strncpy - copies a string
 * @dest: target string
 * @src: target string to be copied
 * @n: Required number of bytes to be copied
 *
 * Return: void
 */

char *_strncpy(char *dest, char *src, int n)
{
	int k = 0;

	while (src[k] != '\0' && k < n)
	{
		dest[k] = src[k];
		k++;
	}
	while (k < n)
	{
		dest[k] = '\0';
		k++;
	}
	return (dest);
}
