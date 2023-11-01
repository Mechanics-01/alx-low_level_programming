#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int i, sum = 0;

	if (ac)
	{
		for (i = 1; i < ac; i++)
		{
			sum = sum + atoi(av[i]);
		}
		printf("The sum of all inputed numbers is : %d\n", sum);
	}
	else
		return (0);
	return (0);
}
