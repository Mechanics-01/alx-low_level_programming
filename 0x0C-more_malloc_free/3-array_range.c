#include "main.h"

/**
 * *array_range - creates an array of intergers and
 * stores numbers min to max
 * @min: smallest number to be stored
 * @max: largest number to be stored
 * Return: pointer to created array
 */

int *array_range(int min, int max)
{
	int *array;
	int len, num;
	int index = 0;

	if (min > max)
		return (0);

	len = (max - min) + 1;

	array = malloc(sizeof(int) * len);
	if (array == 0)
		return (0);

	for (num = min; num <= max; num++)
	{
		array[index] = num;
		index++;
	}
	return (array);
}
