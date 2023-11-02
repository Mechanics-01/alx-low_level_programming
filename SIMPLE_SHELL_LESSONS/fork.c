#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t my_pid;
	pid_t pid;
	pid_t my_ppid;

	printf("Before fork\n");
	pid = fork();

	if (pid == -1)
	{
		perror("Error:Fork Failed");
	}
	printf("After fork\n");
	my_pid = getpid();
	my_ppid = getppid();
	printf("Process ID: %u\n", my_pid);
	printf("Parent ID: %u\n", my_ppid);
	return (0);
}
