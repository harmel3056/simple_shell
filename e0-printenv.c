#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **environ)
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
