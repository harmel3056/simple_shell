#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

char *_getenv(const char *name)
{
	int i = 0;
	size_t len;
       
	len = strlen(name); //works out the length of the variable name (PATH->4) (not inc terminator)

	while (environ[i] != NULL) //environ is null-terminated array
	{
		if (strncmp(environ[i], name, len) == 0 //targets name and names' len
				&& environ[i][len] == '=') //makes sure = follows name, in case of partial match like PATH->PATHWAY conflict
			return (environ[i] + len + 1); //returns pointer to the beginning of the value string
	i++;
	}

	return (NULL);
}

/** this works really well in comparison to my original
 * code which used strtok to extract the NAME portion before
 * strcmp. The problem that created was that we were working
 * with a copy as a result, rather than working with the variable
 * itself.
 * By finding len of the name, we know to only search that number
 * of chars in the environ[i], it can only be a match within those 
 * bounds.
