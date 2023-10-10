#include "dog.h"

/**
 * print_dog - function that prints a struct dog
 * @d: pointer to struct holding dog's info
 * Return: void
 */

void print_dog(struct dog *d)
{
	if (d->name == NULL)
		printf("Name: NIL\n");
	else
		printf("Name: %s\n", d->name);

	if (d->age == 0)
		printf("Age: NIL\n");
	else
		printf("Age: %f\n", d->age);

	if (d->owner == NULL)
		printf("Owner: NIL\n");
	else
		printf("Owner: %s\n", d->owner);
}
