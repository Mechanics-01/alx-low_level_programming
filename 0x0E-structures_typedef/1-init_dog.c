#include "dog.h"

/**
 * init_dog - intilizes a variable of type
 * struct dog
 * @d: pointer to a variable of type struct dog
 * @name: string containing dog's name
 * @age: float containing dog's age
 * @owner: string containing the name of dog's owner
 * Return: void
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == 0)
		return;

	(*d).name = name;
	(*d).age = age;
	(*d).owner = owner;
}
