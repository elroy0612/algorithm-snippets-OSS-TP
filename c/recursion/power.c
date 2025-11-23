/*
 * Title    : Power
 * Problem  : Compute N raised to the power of P
 * Category : recursion
 * Language : C
 * Author   : YeongWoong Kim
 * note     : Supports positive, zero, and negative integer exponents.
 */

#include <stdio.h>

double power(double N, int P);

int main(void)
{
    double N;
    int P;

    printf("N^P (P must be an integer)\n");

    printf("Enter the base number (N): ");
    scanf_s("%lf", &N);

    printf("Enter the exponent (P): ");
    scanf_s("%d", &P);

    printf("%g^%d is %g\n", N, P, power(N, P));

    return 0;
}

double power(double N, int P)
{
    // Base case
    if (P == 0)
        return 1;

    // Handle negative exponent: N^-P = 1 / (N^P)
    if (P < 0)
        return 1.0 / myPower(N, -P);

    // Positive exponent: recursive case
    return N * myPower(N, P - 1);
}
