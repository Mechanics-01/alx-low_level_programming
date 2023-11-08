#include <stdio.h>
#include <stdlib.h>

int main()
{
	setenv("MY_VARIABLE", "Hello, World!", 1);

	char *value = getenv("MY_VARIABLE");
	if (value != NULL)
		printf("Value of MY_VARIABLE: %s\n", value);

	unsetenv("MY_VARIABLE");
	value = getenv("MY_VARIABLE");

	if (value == NULL)
		printf("MY_VARIABLE is unset.\n");

	return (0);
}
