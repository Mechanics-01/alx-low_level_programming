#include "main.h"
/**
 * string_nconcat - concatenates two strings
 * @s1: destination string
 * @s2: source string
 * @n: numbers of characters to be copied
 * Return: copied
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int s1_len = 0;
	unsigned int s2_len = 0;
	unsigned int i;
	char *s;

	/* if NULL is passed, treat as an empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* while at index 0 */
	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[s2_len] != '\0')
		s2_len++;

	if (n >= s2_len)
		n = s2_len;

	/* Memory allocation */
	s = malloc(sizeof(char) * n + sl_len + 1);
	if (s == NULL)
		return (NULL);

	for (i = 0; i < s1_len; i++)
		s[i] = s1[i];

	for (i = 0; i < n; i++)
		s[i + s1_len] = s2[i];

	s[i + s1_len] = '\0';

	return (s);
}
