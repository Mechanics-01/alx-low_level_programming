#ifndef DOG_H
#define DOG_H

#include <stdio.h>

/**
 * struct dog - contains dog info
 * @name: name of dog
 * @age: age of dog
 * @owner: owner of dog
 * Description: Hold all necessary information
 * for dog
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif /*DOG_H*/
