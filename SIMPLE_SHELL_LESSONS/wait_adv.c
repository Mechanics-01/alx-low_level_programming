#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int status, i;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t childpid;
	pid_t parentpid = getpid();

	for (i = 0; i < 5; i++)
	{
		childpid = fork();
		if (childpid == 0)
		{
			execve(argv[0], argv, NULL);
		}
	}
	if (getpid() == parentpid)
	{
		wait(&status);
	}
	return (0);
}
