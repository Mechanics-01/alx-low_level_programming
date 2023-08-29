#include "lists.h"

/**
 * print_listint_len - returns the number of elements
 * 		       in a linked list listint_t list
 * @h: linked list
 *
 * Return: number of nodes as elements
 */

size_t listint_len(const listint_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		h = h->next;
		n++;
	}
	return (n);
}
