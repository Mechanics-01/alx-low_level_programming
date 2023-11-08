#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite)
{
	size_t name_len, value_len, env_len, i;
	char *new_env;
	int env_index;

	if (name == NULL || name[0] == '\0')
		return (-1);

	name_len = strlen(name);
	value_len = (value != NULL) ? strlen(value) : 0;
	env_len = name_len + value_len + 2;

	new_env = malloc(env_len);
	if (new_env == NULL)
		return (-1);

	for (i = 0; i < name_len; i++)
		new_env[i] = name[i];

	new_env[name_len] = '=';
	for (i = 0; i < value_len; i++)
		new_env[name_len + 1 + i] = value[i];

	new_env[env_len - 1] = '\0';
	
	env_index = 0;
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
		if (overwrite)
		{
			free(environ[env_index]);
			environ[env_index] = new_env;
		}
		else
			free(new_env);
	}
	else
	{
		for (i = 0; ; i++)
		{
			if (environ[i] == NULL)
			{
				environ[i] = new_env;
				environ[i + 1] = NULL;
				break;
			}
		}
	}
	return (0);
}
int main ()
{
	_setenv("MY_VARIABLE", "Hello, World!", 1);

	char *value = getenv("MY_VARIABLE");
	if (value != NULL)
		printf("Value of MY_VARIABLE: %s\n", value);

	_setenv("MY_VARIABLE", "Updated Value", 1);
	value = getenv("MY_VARIABLE");
	if (value != NULL)
		printf("Updated Value of MY_VARIABLE: %s\n", value);
	return (0);
}


