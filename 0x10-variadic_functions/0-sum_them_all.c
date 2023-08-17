#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * sum_them_all - a function that return the sum of its numbers
 * @n: a numbers of argument
 * @...: a ellipsis in place of last parameter
 * Return: return the sum on success, 0 if fail.
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list valist;
	unsigned int sum, i;

	if (n == 0)
		return (0);
	sum = 0;
	va_start(valist, n);
	for (i = 0; i < n; i++)
		sum += va_arg(valist, int);
	va_end(valist);
	return (sum);
}
