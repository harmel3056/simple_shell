#include <stdio.h>

extern char **environ;

char *_getenv(const char *name)
{

}

//Use strtok to tokenise the environment lists' array items
//Delimited by the =
//Create a while loop NULL terminated, to search for a match
//arr[0] needs to match the environment variable we are looking for
//If a match is found -- if (strcmp(a, b) == 0) --, a pointer to arr[1] is returned as value
//Else no match found, NULL is returned
