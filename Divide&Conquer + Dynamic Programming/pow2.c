/*
 * Program calculates 2 to the power of n, where n is a natural number given by user
 * 
 * Obvious is to brute-force with O(n) time
 * 
 * Here, Divide&Conquer technique is implemented to achieve O(logn) time
 * 
 * D. Komninos
 */

#include <stdio.h>
#include <limits.h>

// calculate 2 to the power of n, where n is a natural number
// divide and conquer
long double pow2(int n) {

    if(n == 0)
        return 1;

    if(n == 1)
        return 2;

    long double result = pow2(n/2);
    // if n is even
    if(n % 2 == 0)
        return (result*result);
    else  // n is odd
        return (result*result*2);       
}

// Driver code
int main(void) {

    int n;

    while(1) {
        printf("\nGive n to calculate 2 to the power of n (n must be a natural number): ");
        scanf("%d", &n);
        if(n < 0 || n > INT_MAX)
            printf("\nInput is not a natural number\n");
        else 
            break;
    }

    printf("\nResult: %g\n", (double)pow2(n));
    printf("\n");
}
