#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: First string
 * @s2: Second string
 * Return: pointer to catenated string
 */

char *str_concat(char *s1, char *s2)
{
	unsigned int i, j, size1, size2;
	char *str;

	if (s1 != NULL)
	{
		for (i = 0; s1[i] != '\0'; i++)
			;
	}
	size1 = i;
	if (s2 != NULL)
	{
		for (j = 0; s2[j] != '\0'; j++)
			;
	}
	size2 = j;
	str = malloc(sizeof(char) * (size1 + size2 + 2));
	if (str == NULL)
		return (NULL);
	if (s1 == NULL && s2 == NULL)
	{
		str[0] = '\0';
		return (str);
	}
	for (i = 0; s1[i] != '\0'; i++)
	{
		str[i] = s1[i];
	}
	if (s1 == NULL)
		i = 0;

	for (j = 0; s2[j] != '\0'; j++)
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';
	return (str);
}

