#include "main.h"

/**
 * is_prime_number - checks for prime numbers
 * @n: number to be checked
 * Return: 1 if number is prime and 0 otherwise
 */

int is_prime_number(int n)
{
	int a = 2;

	if (n <= 2)
		return (n == 2 ? 1 : 0);
	if (n % 2 == 0)
		return (0);
	return (is_prime(n, a));
}

/**
 * is_prime - checks for prime numbers
 * @n: number to be checked
 * @a: dividend
 * Return: int
 */

int is_prime(int n, int a)
{
	if (n != a && n % a == 0)
		return (0);
	else if (n == a)
		return (1);
	return (is_prime(n, a + 1));
}
