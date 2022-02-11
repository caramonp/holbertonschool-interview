#include "palindrome.h"

/**
 * is_palindrome - checks if is palindrome
 * @n: number.
 * Return: 1 or 0
 */

int is_palindrome(unsigned long n)
{
	unsigned long aux = 0, number = n;

	while (number)
	{
		aux = (aux * 10) + (number % 10);
		number /= 10;
	}
	return (n == aux ? 1 : 0);
}
