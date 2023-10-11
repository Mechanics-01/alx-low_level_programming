#include "dog.h"

/**
 * new_dog - function that creates a new dog
 * @name: name of the new dog
 * @age: age of the new dog
 * @owner: owner of the new dog
 * Return: new struct dog
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	new_dog->name = malloc(sizeof(name));
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	new_dog->owner = malloc(sizeof(owner));
	if (new_dog->owner == NULL)
	{
		free(new_dog);
		free(new_dog->name);
		return (NULL);
	}
	str_cpy(new_dog->name, name);
	new_dog->age = age;
	str_cpy(new_dog->owner, owner);

	return (new_dog);
}

/**
 * str_cpy - copies string to a given memory
 * @dest: destination of string
 * @ini: where the string is
 * Return: char
 */
char *str_cpy(char *dest, char *ini)
{
	int len = 0;

	for (len = 0; ini[len] != '\0'; len++)
	{
		dest[len] = ini[len];
	}
	dest[len] = ini[len];
	return (dest);
}
