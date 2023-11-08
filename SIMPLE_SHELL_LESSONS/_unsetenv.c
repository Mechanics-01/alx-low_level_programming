#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name)
{
	int env_index;
	size_t name_len;
	int i;

	if (name == NULL || name[0] == '\0')
		return (-1);
	
	env_index = 0;
	name_len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0)
		{
			env_index = i;
			break;
		}
	}
	if (env_index != 0)
	{
		free(environ[env_index]);
		
		for (i = env_index; environ[i] != NULL; i++)
			environ[i] = environ[i + 1];
		return (0);
	}
	return (-1);
}

int main(void)
{
	setenv("MY_VARIABLE", "Hello, World", 1);

	char *value = getenv("MY_VARIABLE");
	if (value != NULL)
		printf("Value of MY_VARIABLE: %s\n", value);

	_unsetenv("MY_VARIABLE");
	value = getenv("MY_VARIABLE");
	if (value == NULL)
		printf("MY_VARIABLE is unset: \n");
	return (0);
}
