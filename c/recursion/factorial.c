/*
 * Title    : Factorial
 * Problem  : Compute the factorial of a given non-negative integer.
 * Category : recursion
 * Language : C
 * Author   : YeongWoong Kim
 * note     : Uses a recursive function to compute N! (supports 0! to 20!)
 */

#include <stdio.h>

unsigned long long factorial(int);

int main()
{
	int n;

	// Prompt user for input
	printf("Enter an integer to calculate its factorial (0~20): ");
	scanf_s("%d", &n);

	// Input validation (negative integer)
	if (n < 0) {
		printf("Error : The number is a negative integer.\n");
		return 1;
	}
	
	// Input validation (overflow)
	if (n > 20) {
		printf("Error : Overflow will occur if n is bigger than 20.\n");
		return 1;
	}

	// Compute and print factorial
	printf("%d! = %llu\n", n, factorial(n));

	return 0;
}

unsigned long long factorial(int n)
{
	// Base case
	if (n == 0)
		return 1;
	
	// Recursive case
	return n * factorial(n - 1);
}

