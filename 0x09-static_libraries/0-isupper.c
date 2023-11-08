#include "main.h"
/**
 * _isupper - Checks for uppercase character
 * @c: target
 * Return: 0
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}
