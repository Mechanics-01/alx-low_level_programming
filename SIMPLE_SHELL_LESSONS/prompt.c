#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buff = NULL;
	size_t n;
	int n_read;
	
	while (1)
	{
		printf("$ ");
		if (n_read = getline(&buff, &n, stdin) != -1)
		{
			printf("%s\n", buff);
	
		}
		else
			break;
	}
	free(buff);
	return (0);
}
