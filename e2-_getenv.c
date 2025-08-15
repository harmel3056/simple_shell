#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

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

int main(void)
{
	char *path_val;

	path_val = _getenv("PATH");

	if (path_val != NULL)
	{
		printf("PATH = %s\n", path_val);
		free(path_val);
	}

	else
		printf("nah mate\n");

	return (0);
}

//Use strtok to tokenise the environment lists' array items
//Delimited by the =
//Create a while loop NULL terminated, to search for a match
//arr[0] needs to match the environment variable we are looking for
//If a match is found -- if (strcmp(a, b) == 0) --, a pointer to arr[1] is returned as value
//Else no match found, NULL is returned
