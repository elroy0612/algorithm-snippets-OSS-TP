/*
 * Title    : Fibonacci Sequence
 * Problem  : Compute the n-th Fibonacci number using a recursive function.
 * Category : recursion
 * Language : C
 * Author   : YeongWoong Kim
 * note     : Recursive Fibonacci implementation (0~46).
 */

#include <stdio.h>

int fibo(int n) {
	if (n == 0)  // Base case: Fibo(0)
		return 0;
	else if (n == 1)  // Base case: Fibo(1)
		return 1;
	else  // Recursive relation
		return fibo(n - 1) + fibo(n - 2);
}

int main() {
	printf("Fibonacci Sequence, Fibo(n) (0~46)\n");
	printf("Enter an integer n : ");
	int num;
	scanf_s("%d", &num);

	if (num < 0) {  // Input validation: n must be non-negative.
		printf("Error: n must be non-negative.\n");
		return 1;
	}
	else if (num > 46) {  // Input validation: prevent overflow
		printf("Error: Overflow will occur if n is bigger than 46.\n");
		return 1;
	}
	
	if (num>=40)  // Recursive delay
		printf("Calculating..... Please wait for a few seconds.\n");  

	printf("Fibo(%d) = %d\n", num, fibo(num));
	
	return 0;
}
