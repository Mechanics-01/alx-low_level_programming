#include "main.h"

/**
 * alloc_grid - returns a pointer to a 2 dimensional
 * array of integers.
 * @width: width of array
 * @heigth: height of array
 * Return: pointer to 2 dimensional array
 */

int **alloc_grid(int width, int heigth)
{
	int i, j;

	int **grid;

	if (width <= 0 || heigth <= 0)
	{
		return (NULL);
	}

	grid = (int **)malloc(sizeof(int *) * heigth);

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < heigth; i++)
	{
		grid[i] = (int *)malloc(sizeof(int) * width);
		if (grid[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(grid[j]);
		
			free(grid);
			return (NULL);
		}
		for (j = 0; j < width; j++)
		{
			grid[i][j] = 0;
		}
	}
	return (grid);
}

