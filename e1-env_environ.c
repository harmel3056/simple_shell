#include <stdio.h>

extern char **environ;

int main(int ac, char **av, char **env)
{
	unsigned int i = 0;
	unsigned int j = 0;

	while (env[j] != NULL)
	{
		printf("%s\n", env[j]);
		j++;
	}

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
