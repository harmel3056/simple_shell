#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

/**
 */

int main(void)
{
	char *line = NULL;	//Feeds getline buffer, NULL to ensure malloc
	size_t len = 0;		//Holds allocated size of getline buffer
	char *token;		//Hosts strtok, ret pointer to next token

	printf("$ ");
	getline(&line, &len, stdin);	//line now points to buffer containing line read from stdin, len holds malloc'd buffer size

	line[strcspn(line, "\n")] = '\0';	//replaces '\n' with '\0' to remove newline appld by getline

	token = strtok(line, ",");	//initialises tokenising with strtok

	while (token != NULL)		//token/pointer is valid
	{
		printf("%s\n", token);		//print token segment
		token = strtok(NULL, ",");	//tokenise following segments of string, NULL to continue same string, strtok remembers where you're up to
	}

	free(line);		//release malloc
	return (0);
}
