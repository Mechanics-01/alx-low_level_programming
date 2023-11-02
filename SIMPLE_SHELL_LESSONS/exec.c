#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
	char *envp[] = {"MY_VARIABLE=123", "PATH_T= ls", NULL};

	printf("Before execve\n");
	if (execve(argv[0], argv, envp) == -1)
	{
		perror("Error:");
	}
	printf("After execve\n");
	return (0);
}
