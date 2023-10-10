#include "dog.h"

/**
 * free_dog - frees memory held by passed struct
 * @d: struct to free
 * Return: void
 */

void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
