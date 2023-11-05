#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
	int i;
	char *env;

	if (name == NULL || environ == NULL)
		return NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		env = environ[i];
		if (strncmp(env, name, strlen(name)) == 0 && env[strlen(name)] == '=')
			return (env + strlen(name) + 1);
	}
	return (NULL);
}

int main(void)
{
	char *path = _getenv("PATH");

	if (path != NULL)
		printf("The valiue of the PATH environment is: %s\n", path);
	else
		printf("The PATH environment is not set.\n");

	return (0);
}
