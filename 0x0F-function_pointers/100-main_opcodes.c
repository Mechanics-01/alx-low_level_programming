#include <stdio.h>
#include <stdlib.h>

/**
 * main - a function prints opcode
 * @argc: arguments from comment line
 * @argv: each arguments contents
 *
 * Return: 0 on success, others if fail.
 */

int main(int argc, char **argv)
{
	int a, i;

	i = -1;
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}
	a = atoi(argv[1]);
	if (a < 0)
	{
		printf("Error\n");
		exit(2);
	}
	while (++i < a && main)
		printf("%02x ", ((unsigned char *)main)[i]);
	printf("\n");
	return (0);
}
