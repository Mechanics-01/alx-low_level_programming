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

	if (s1 == NULL)
		s1[0] = '\0';
	if (s2 == NULL)
		s2[0] = '\0';

	for (i = 0; s1[i] != '\0'; i++)
		;
	size1 = i;

	for (j = 0; s2[j] != '\0'; j++)
		;
	size2 = j;

	str = malloc(sizeof(char) * (size1 + size2 - 1));

	if (str == NULL)
		return (NULL);

	for (i = 0; s1[i] != '\0'; i++)
	{
		str[i] = s1[i];
	}
	for (j = 0; s2[j] != '\0'; j++)
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = '\0';

	return (str);
}

