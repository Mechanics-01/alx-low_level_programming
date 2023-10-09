#include "main.h"

/**
 * string_nconcat - concatenates two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * @n: number of bytes to use from s2
 * Return: pointer to new string, else NULL if fails
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int i, j, size1 = 0, size2 = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";


	while (s1[size1] != '\0')
		size1++;

	while (s2[size2] != '\0')
		size2++

	if (n >= size2)
		n = size2;

	str = malloc(sizeof(char) * (size1 + n + 1));

	if (str == NULL)
		return (NULL);

	for (i = 0; i < size1; i++)
		str[i] = s1[i];

	for (j = 0; j < n; j++, i++)
	{
		str[i] = s2[j];
	}
	str[i] = '\0';

	return (str);
}
