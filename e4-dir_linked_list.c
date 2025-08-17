#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

typedef struct linked_list
{
	char *str;
	struct linked_list *prev;
	struct linked_list *next;
} list_t;

char *_getenv(const char *name);
void free_list(list_t *head);


/**
 * dir_linked_list - makes a linked list from the PATH directory
 *
 */

list_t *dir_linked_list(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *tail;
	char *directory;
	char *token;

	directory = strdup(_getenv(str));	//returns copy of value of PATH dir
	
	if (directory == NULL)
		return (NULL);

	token = strtok(directory, ":");	//
	
	while (token != NULL)
	{
		new_node = malloc(sizeof(list_t));      //assigns memory for the new node

		if (new_node == NULL)
		{
			free(directory);
			return (NULL);
		}

		new_node->str = strdup(token);
		new_node->prev = tail;
		new_node->next = NULL;

		if (tail == NULL)
			*head = new_node;
		else
			tail->next = new_node;

		tail = new_node;
		token = strtok(NULL, ":");
	}

	free(directory);
	return (*head);
}


/**
 * searches environ for a particular environment variable, and returns a pointer to its value
 * see e2b-_getenv.c for code breakdown if needed
 */

char *_getenv(const char *name)
{
	int i = 0;
	size_t len;
       
	len = strlen(name);

	while (environ[i] != NULL) //environ is null-terminated array
	{
		if (strncmp(environ[i], name, len) == 0 //targets name and names' len
				&& environ[i][len] == '=') //ensure = follows name
			return (environ[i] + len + 1); //ret pointer to beg of the value string
	i++;
	}

	return (NULL);
}

void free_list(list_t *head)
{
    list_t *temp;

    while (head != NULL)
    {
        temp = head->next;   //save the next node while you free
        free(head->str);     //free the strdup string
        free(head);          //free the node itself
        head = temp;         //move to next node
    }
}

int main(void)
{
    list_t *head = NULL;
    dir_linked_list(&head, "PATH");

    list_t *current = head;
    while (current)
    {
        printf("%s\n", current->str);
        current = current->next;
    }

    free_list(head); /* cleanup */

    return (0);
}
