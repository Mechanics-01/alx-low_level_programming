#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n)
 * @head: linked list
 * Return: 0 when list is empty, or sum of all data
 */

int sum_listint(listint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (0);
	while (head)
	{
		sum = sum + head->n;
		head = head->next;
	}
	return (sum);
}
