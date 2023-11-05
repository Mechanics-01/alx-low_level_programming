#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int status;
	char *buff = NULL;
	size_t n = 0;
	ssize_t line;
	char *argv[] = {buff, NULL};
	pid_t childpid;

	while (1)
	{
		printf("$ ");
		line = getline(&buff, &n, stdin);
		if (line == -1)
		{
			perror("Error: Dynamic allocation failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			if (line > 0 && buff[line -1] == '\n')
				buff[line -1] = '\0';
		}
		if (line > 0)
		{
			childpid = fork();
			if (childpid == -1)
			{
				perror("Fork failed");
				exit(EXIT_FAILURE);
			}
			if (childpid == 0)
			{
				execve(buff, argv, NULL);
				perror("Execve Failed");
				exit(EXIT_FAILURE);
			}
			wait(&status);
		}
	}
	free(buff);
	return (0);
}
