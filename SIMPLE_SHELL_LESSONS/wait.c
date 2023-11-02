#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
	int status;
	int i;
	pid_t childpid;
	pid_t parentpid = getpid();

	for (i = 0; i < 3; i++)
	{
		childpid = fork();
		if (childpid == 0)
		{
			printf("Child process with PID %u\n", getpid());
			exit(i);
		}
	}
	if (getpid() == parentpid)
	{
		for (i = 0; i < 3; i++)
		{
			childpid = wait(&status);
			if (WIFEXITED(status))
			{
				printf("Child proecess with PID %d terminated with status %d\n", childpid, WEXITSTATUS(status));
			}
		}
	}
	return (0);
}
