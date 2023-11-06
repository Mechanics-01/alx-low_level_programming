#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *head = NULL;

void printList()
{
	node *p = head;
	printf("\n[");

	while (p != NULL)
	{
		printf(" %d ", p->data);
		p = p->next;
	}
	printf("]\n");
}
void insertatbegin(int data)
{
	node *new;
	new = malloc(sizeof(node));
	new->data = data;
	new->next = head;
	head = new;
}

void insertatend(int data)
{
	node *new;
	new = malloc(sizeof(node));
	new->data = data;
	node *temp;
	temp = head;

	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}
void insertafternode(int data, int key)
{
	node *new;
	new = malloc(sizeof(node));
	new->data = data;
	node *temp;
	temp = head;

	while (temp != NULL)
	{
		if (temp->data == key)
		{
			new->next = temp->next;
			temp->next = new;
			break;
		}
		temp = temp->next;
	}
}

void deleteatbegin(void)
{
	head = head->next;
}

void deleteatend(void)
{
	node *new;
	new = head;
	while (new->next->next != NULL)
		new = new->next;
	new->next = NULL;
}

void main(void)
{
	int k = 0;
	insertatbegin(12);
	insertatend(22);
	insertatend(30);
	insertafternode(90, 12);
	insertatend(50);
	insertatend(55);
	insertafternode(99, 55);
	printf("Linked List: ");

	printList();
	deleteatbegin();
	deleteatend();
	printList();
}
