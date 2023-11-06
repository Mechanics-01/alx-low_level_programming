#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct path_node
{
	char *dir;
	struct path_node *next;
}pathnode;

pathnode *addtolist(pathnode *head, char *dir)
{
	pathnode *new_node, *temp;
	new_node = malloc(sizeof(pathnode));
	if (new_node == NULL)
	{
		printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->dir = dir;
	new_node->next = NULL;

	if (head == NULL)
		head = new_node;
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
	return (head);
}
void printlist(pathnode *head)
{
	pathnode *temp;
	temp = head;
	while (temp != NULL)
	{
		printf("%s\n", temp->dir);
		temp = temp->next;
	}
}
void freelist(pathnode *head)
{
	pathnode *temp = head;
	while (temp != NULL)
	{
		pathnode *current = temp;
		temp = temp->next;
		free(current);
	}
}
int main (void)
{
	char *pathenv = getenv("PATH");
	if (pathenv == NULL)
	{
		printf("PATH environment variable not found\n");
		return (1);
	}

	char *token = strtok(pathenv, ":");
	pathnode *pathlist = NULL;
	while (token != NULL)
	{
		pathlist = addtolist(pathlist, token);
		token = strtok(NULL, ":");
	}
	printf("PATH Directories:\n");
	printlist(pathlist);

	freelist(pathlist);

	return (0);
}
