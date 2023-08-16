#include "function_pointers.h"
/**
 * print_name - prints a name
 * @name: input string
 * @f: function pointer
 */

void print_name(char *name, void (*f)(char *))
{
	if (name != NULL)
		(*f)(name);
	return;
}
