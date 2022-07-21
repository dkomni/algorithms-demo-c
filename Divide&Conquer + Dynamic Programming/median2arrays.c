/* 
 * Given two arrays of size n sorted in ascending order, the problem
 * is to find the median of the 2n numbers in O(logn).
 * 
 * One solution would be to merge the two arrays in O(n) with the classic
 * merge() subroutine that mergeSort algorithm utilizes and pick the median
 * in O(1).
 * 
 * Here, with Divide&Conquer technique we construct a modified BinarySearch
 * algorithm (same logic) that finds the solution in O(logn)
 * 
 * D. Komninos
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utility.h"

// modified binary search to find median of 2n numbers from two arrays
// when n is even, median is rounded down
int median2arrays(int *X, int *Y, int n) {
    
    if(n == 1)
        return (X[0] + Y[0])/2;
    if(n == 2)
        return (max(&X[0], &Y[0]) +  
                min(&X[1], &Y[1])) / 2; 
    
    int mX, mY; // medians of X and Y respectively
    // cases when n is even or odd
    if(n % 2 == 0) {
        mX = (X[n/2] +X[n/2 - 1])/2;
        mY = (Y[n/2] +Y[n/2 - 1])/2;
    } else {
        mX = X[n/2]/2;
        mY = Y[n/2]/2;
    }
    /* if medians of X and Y are the same, return the median */
    if(mX == mY)
        return mX;
    /* if median of X is greater than median of Y,
       then median of all numbers must be in X[0...mX] and Y[mY...n] */
    if(mX > mY) {
        if(n % 2 == 0)
            return median2arrays(X, Y+n/2-1, n-n/2+1);
        else
            return median2arrays(X, Y+n/2, n-n/2);
    }
    /* if median of X is less than median of Y,
       then median of all numbers must be in X[mX...n] and Y[0...mY] */
    if(n % 2 == 0)
        return median2arrays(X+n/2-1, Y, n-n/2+1);
    else
        return median2arrays(X+n/2, Y, n-n/2);
}

// function to compare two elements of an array
// to be used by qsort() from stdlib
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Driver code
int main(void) {

    int usr;    // # of elements in each array
    int *X, *Y; // data arrays

    printf("\nInsert the number of elements to create two random integer sorted arrays in ascending order (each): ");
    scanf("%d",&usr);
    
    if(usr < 2) {
        printf("\nInvalid input.Cannot create an array with less than 2 elements\nProgram will exit.\n");
        exit(0);
    }

    if(usr > INT_MAX) {
        printf("\nInvalid input.INT_MAX exceeded\nProgram will exit.\n");
        exit(0);
    }

    X = createArray(usr);                   // create random array X
    qsort(X, usr, sizeof(int), cmpfunc);    // sort array X with in-built quicksort

    Y = createArrayPosNeg(usr);             // create random array Y
    qsort(Y, usr, sizeof(int), cmpfunc);    // sort array Y with in-built quicksort

    printf("\nX array with %d elements created: ", usr);
    printArray(X, usr);      // print random array X
    printf("\nY array with %d elements created: ", usr);
    printArray(Y, usr);      // print random array Y

    int median = median2arrays(X, Y, usr);
    printf("\nMedian of %d numbers from both arrays X and Y: %d\n", 2*usr, median);

    // free memory
    free(X);    
    free(Y);
    printf("\n");
}