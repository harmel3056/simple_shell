#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/**
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *token;

	printf("$ ");
	getline(&line, &len, stdin);

	line[strcspn(line, "\n")] = '\0';

	token = strtok(line, ",");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ",");
	}

	free(line);
	return (0);
}
