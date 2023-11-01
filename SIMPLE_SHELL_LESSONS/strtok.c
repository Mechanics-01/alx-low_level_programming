#include <stdio.h>
#include <string.h>

int main(int ac, char **av)
{
	char *buff;
	const char delim[] = " ";
	if (ac)
	{
		buff = strtok(av[1], delim);
		while (buff != NULL)
		{
			printf("Token: %s\n", buff);
			buff = strtok(NULL, delim);
		}
	}
	return (0);
}
