#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_ARGS 64 		//Limits array args to 63 + 1 NULL for execve()

int launch_exec_child(char *argv[]);

/**
 */

int main(void)
{
	char *line = NULL;	//Feeds getline buffer, NULL to ensure malloc
	size_t len = 0;		//Holds allocated size of getline buffer
	char *token;		//Hosts strtok, ret pointer to next token
	char *argv[MAX_ARGS];	//Allocates enough space for tokens + NULL
	int i = 0;

	printf("cisfun$ ");
	getline(&line, &len, stdin);	//line now points to buffer containing line read from stdin, len holds malloc'd buffer size

	line[strcspn(line, "\n")] = '\0';	//replaces '\n' with '\0' to remove newline appld by getline

	token = strtok(line, ",");	//initialises tokenising with strtok

	while (token != NULL && i < MAX_ARGS - 1)	//token/pointer is valid & args within limit
	{
		argv[i] = token;		//assigns delimited arg to array[i]
		i++;				//increments array index
		token = strtok(NULL, ",");	//tokenise following segments of string, NULL to continue same string, strtok remembers where you're up to
	}
	argv[i] = NULL;			//NULL tells execve the array is complete, is a terminator

	launch_exec_child(argv);		//Calls fork helper function below



	free(line);		//release malloc
	return (0);
}

/**
 * launch_exec_child - forks main() process, then runs execve with argv
 * data parsed above in the child process. The parent process waits
 * for the child process to complete.
 */

int launch_exec_child(char *argv[])
{
	pid_t pid;
	int status;
	extern char **environ;

	pid = fork();		//Duplicates current process into 2, parent and child

	if (pid == 0)		//Child process
		execve(argv[0], argv, environ);	//takes argv array from strtok array

	else if (pid > 0)	//Parent process
		wait(&status);	//Waits for child to finish

	else			//Error return
	{
		perror("fork failed");
		return (1);
	}
}
