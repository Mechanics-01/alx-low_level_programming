#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root
 * of a number n
 * @n: number whose square root is required
 * Return: int of the square root of the number
 */

int _sqrt_recursion(int n)
{
	int sq = 1;

	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		return (n);
	return (is_sqrt(n, sq));
}

/**
 * is_sqrt - check if number is natural square root or not
 * @n: number to be checked
 * @square: test number
 * Return: int
 */

int is_sqrt(int n, int square)
{
	if (square * square == n)
		return (square);
	else if (square * square < n)
		return (is_sqrt(n, square + 1));
	else if (square * square > n)
		return (-1);
	return (-1);
}
