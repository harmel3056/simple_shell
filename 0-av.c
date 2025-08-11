#include <stdio.h>

/**
 */

int main(int ac, char **av)
{
	int s;

	while (av[s] != NULL)
	{
		printf("%s, \n", av[s]);
		s++;
	}
}
