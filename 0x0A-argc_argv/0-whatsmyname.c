#include "main.h"
#include <stdio.h>

/**
 * main - this is a function to print its name
 * @argc: argc parameter
 * @argv: an array of a command listed
 * Return: 0 for success
 */
int main(int argc, char *argv[])
{
	if (argc > 0)
	{
		printf("%s\n", *argv);
	}
	return (0);
}
