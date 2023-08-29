#include "lists.h"
/**
 * add_nodeint - adds a new node in front of the list
 * @head: head of the linked list.
 * @n: number to store in the list.
 * Return: address of the new element else NULL.
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *New_node;

	New_node = (listint_t *)malloc(sizeof(listint_t));

	if (New_node == NULL)
		return (NULL);

	New_node->n = n;
	New_node->next = *head;
	*head = New_node;

	return (New_node);
}
