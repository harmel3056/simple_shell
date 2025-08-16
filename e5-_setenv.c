#include <stdio.h>

extern char **environ;
char *_getenv(const char *name);

/**
 * _setenv - adds, changes, and deletes environment variables
 * @name: name of the environment variable
 * @value: value to assign
 * @overwrite: 1 to overwrite, 0 only to append env variable
 * if it doesn't exist
 *
 * Return: 0 on success, -1 on failure
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	char var_exists;
	char *new_var;
	size_t len;

	len = strlen(name) + strlen(value) + 2; //+1 fpr '=' +1 for '\0'
	new_var = malloc(len);		//reserves space for the new variable and its value

	sprintf(new_var, "%s=%s", name, value); //allocates 'name=value' into new_var buffer

	if (new_var == NULL)
		return (-1)

	var_exists = _getenv(name); //checks if environment variable exists in env list

	if (var_exists != NULL) //ie if the name searched for exists
	{

	else


		free(name);
}

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

		if (env_copy == NULL || name == NULL)
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
