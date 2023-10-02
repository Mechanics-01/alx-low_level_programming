#include "main.h"

/**
 * main - add positive integers
 * @argc: argument count
 * @argv: argument vector
 * Return: integer
 */

int main(int argc, char *argv[])
{
	int i, j, sum;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
			{
				printf("Error\n");
				return (1);
			}

		}
		sum = sum + atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}
