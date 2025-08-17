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

	//THIS BIT WE USE TO APPEND NEW ENVIRONMENT VARIABLE//
	len = strlen(name) + strlen(value) + 2; //+1 fpr '=' +1 for '\0'
	new_var = malloc(len);		//reserves space for the new variable and its value

	sprintf(new_var, "%s=%s", name, value); //allocates 'name=value' into new_var buffer
	// DOWN TO HERE//


	if (new_var == NULL)
		return (-1)

	var_exists = _getenv(name); //checks if environment variable exists in env list

	if (var_exists != NULL && overwrite == 1) //ie if the name searched for exists
	{
		var_exists = new_var; 		//malloc'd space overwrites current var
	}
	
	if (var_exists == NULL && overwite == 1 || var_exists == NULL && overwrite == 0)
	{ **THIS IS WHERE YOU'RE UP TO!!! HAVE A NICE DINNER!**

	else
		return (0);  //we do nothing if var exists and overwrite is 0

		free(name);
}


char *_getenv(const char *name)
{
	int i = 0;
	size_t len;
       
	len = strlen(name);

	while (environ[i] != NULL) //environ is null-terminated array
	{
		if (strncmp(environ[i], name, len) == 0 //targets name and names' len
				&& environ[i][len] == '=') //ensure = follows name
			return (environ[i]); //mod, ret pointer to beg of env variable
	i++;
	}

	return (NULL);
}
