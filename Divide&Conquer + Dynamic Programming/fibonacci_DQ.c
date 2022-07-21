/*
 * Program calculates the n-th Fibonacci number, where n is a natural number given by user
 * 
 * Obvious is to brute-force by recursion with exponential complexity
 * 
 * Moreover, with Dynamic Programming approach, linear complexity can be achieved
 * 
 * Here, Divide&Conquer technique is implemented to achieve O(logn) time
 * based on the 2x2 matrix {{1,1},{1,0}}, where if we calculate this matrix to the power
 * of n, the (n+1)-th Fibonacci number will be in position [0][0].
 * So, the problem is reduced to calculating a number to the power of n,
 * where the number is a 2x2 matrix that its multiplication with another 2x2 matrix
 * is assumed to take constant time O(1) to solve
 * 
 * D. Komninos
 */

#include <stdio.h>
#include <limits.h>

// multiply two 2x2 matrices in O(1)
void multiply(int F[2][2], int M[2][2]) { 

	int x = F[0][0] * M[0][0] + F[0][1] * M[1][0]; 
	int y = F[0][0] * M[0][1] + F[0][1] * M[1][1]; 
	int z = F[1][0] * M[0][0] + F[1][1] * M[1][0]; 
	int w = F[1][0] * M[0][1] + F[1][1] * M[1][1]; 
	
	F[0][0] = x; 
	F[0][1] = y; 
	F[1][0] = z; 
	F[1][1] = w; 
}

// calculate the power to the n of 2x2 matrix
void power(int F[2][2], int n) {

    if(n == 0 || n == 1)
        return;

    int M[2][2] = {{1,1}, {1,0}};

    power(F, n/2);
    if(n % 2 == 0)  // n is even
        multiply(F, F);
    else    // n is odd
        multiply(F, M);
}

// Function that calculates the n-th Fibonacci number
int fibonacci(int n) {

    int F[2][2] = {{1,1}, {1,0}};

    if(n == 0)
        return 0;

    power(F, n-1);
    return F[0][0];
}

// Driver code
int main(void) {

    int n;

    while(1) {
        printf("\nGive n to calculate the n-th Fibonacci number (n must be a natural number): ");
        scanf("%d", &n);
        if(n < 0 || n > INT_MAX)
            printf("\nInput is not a natural number\n");
        else 
            break;
    }

    printf("\nResult: %d\n", fibonacci(n));
    printf("\n");
}