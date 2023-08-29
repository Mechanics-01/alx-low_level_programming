#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end
 * of a list_t list.
 * @head: head of the linked list.
 * @n: integer to store in the list.
 * Return: address of the new element
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *New_node;

	New_node = (listint_t *) malloc(sizeof(listint_t));
	if (New_node == NULL)
		return (NULL);

	New_node->n = n;
	New_node->next = NULL;
	listint_t *temp;

	temp = *head;

	if (temp == NULL)
		*head = New_node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = New_node;
	}
	return (New_node);
}
