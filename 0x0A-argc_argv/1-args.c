#include "main.h"

/**
 * main - prints the number of arguments
 * passed to it
 * @argc: number of argument passed
 * @argv: argument vectors
 * Return: integer
 */

int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
