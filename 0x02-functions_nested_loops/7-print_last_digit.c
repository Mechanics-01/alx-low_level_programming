#include "main.h"
/**
 * print_last_digit - function that print last digit of a number
 * @n: number to be targeted
 * Return: returns value of last digit
 */
int print_last_digit(int n)
{
	int last_digit = n % 10;

	if (n < 0)
		last_digit *= -1;
	_putchar(last_digit + 48);
	return (last_digit);
}
