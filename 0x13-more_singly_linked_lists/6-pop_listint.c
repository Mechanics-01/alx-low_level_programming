#include "lists.h"

/**
 * pop_listint - Deletes the head node of a listint_t list.
 * @head: A pointer to the address of the
 * head of the listint_t list.
 * Return: If the linked list is empty - 0.
 */

int pop_listint(listint_t **head)
{
	listint_t *temp;
	int head_value;

	if (*head == NULL)
		return (0);
	temp = *head;
	head_value = (*head)->n;
	*head = (*head)->next;

	return (head_value);
}
