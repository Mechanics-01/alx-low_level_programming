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
	char *dog_name;
	char *dog_owner;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (new_dog);

	dog_name = malloc(sizeof(name));
	if (dog_name == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	dog_owner = malloc(sizeof(owner));
	if (dog_owner == NULL)
	{
		free(new_dog);
		free(dog_name);
		return (NULL);
	}


	new_dog->name = str_cpy(dog_name, name);
	new_dog->age = age;
	new_dog->owner = str_cpy(dog_owner, owner);

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
