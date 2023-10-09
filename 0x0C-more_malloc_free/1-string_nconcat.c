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
	unsigned int i, j, size1, size2;

	if (s1 == 0)
		s1 = "";
	if (s2 == 0)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		size1++;

	for (i = 0; s2[i] != '\0'; i++)
		size2++;
	if (n >= size2)
		n = size2;

	str = malloc(sizeof(char) * (size1 + n + 1));

	if (str == 0)
		return (0);

	for (j = 0; j < size1; j++)
		str[j] = s1[j];

	for (j = 0; j < n; j++)
	{
		str[size1] = s2[j];
		size1++;
	}
	str[size1] = '\0';

	return (str);
}
