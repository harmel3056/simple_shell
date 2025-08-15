#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;
char *_getenv(const char *name);

int main(void)
{
	char *path_dir;
	char *path_dir_list;

	path_dir = _getenv("PATH");
	path_dir_list = strtok(path_dir, ":");

	if (path_dir == NULL)
	{
		free(path_dir);
		return (1);
	}

	while (path_dir_list != NULL)
	{
		printf("%s\n", path_dir_list);
		path_dir_list = strtok(NULL, ":");
	}

	free(path_dir);
	return (0);
}

/**
 */		

char *_getenv(const char *name)
{
	char *var;
	char *val;
	char *env_copy; //make copy of environ to prevent strtok modifying the environ itself
	char *result;
	int i = 0;

	while (environ[i] != NULL)
	{
		env_copy = strdup(environ[i]);

		if (env_copy == NULL)
			return (NULL);

		var = strtok(env_copy, "=");
		val = strtok(NULL, "=");

		if (strcmp(var, name) == 0)
		{
			if (val != NULL)
			       result = strdup(val);
			else
				result = NULL;

			free(env_copy);
			return (result);
		}

	free(env_copy);
	i++;
	}

	return (NULL);
}

//use _getenv to get PATH value
//use strtok to access value pointer and delimit the items using :
//printf %s\n each array item with an incrementing while loop
