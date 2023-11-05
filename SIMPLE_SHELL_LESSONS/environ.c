#include <stdio.h>

extern char **environ;

int main(int ac, char **arg, char **env)
{
	printf("Address of env: %p\n", env);
	printf("Address of environ: %p\n", environ);

	if (env == environ)
		printf("env and environ have the same address.\n");
	else
		printf("env and environ do not have the same address.\n");

	return (0);
}
