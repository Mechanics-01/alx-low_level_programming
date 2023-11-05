#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printpath(void)
{
	char *path = getenv("PATH");

	if (path != NULL)
	{
		char *token = strtok(path, ":");

		while (token != NULL)
		{
			printf("%s\n", token);
			token = strtok(NULL, ":");
		}
	}
	else
		printf("The PATH environment is not set\n");
}
int main(void)
{
	printpath();
	return (0);
}
