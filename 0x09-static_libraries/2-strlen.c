#include "main.h"
/**
 * _strlen - Returns the length of a string
 * @s: target string
 *
 * Return: length of string
 */

int _strlen(char *s)
{
	int i, length = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		length++;
	}
	return (length);
}
