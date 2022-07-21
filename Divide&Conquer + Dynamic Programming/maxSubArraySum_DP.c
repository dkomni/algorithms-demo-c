/*
 * Dynamic Programming algorithm to find the subarray with the maximum
 * sum in an array (Kadane's algorithm)
 * 
 * Obvious is to use two nested loops resulting in quadratic complexity.
 * 
 * With Divide&Conquer technique, we will achieve O(nlogn) time complexity.
 * Moreover, with Dynamic Programming, linear time
 * complexity can be achieved (O(n)).
 * 
 * D. Komninos
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "utility.h"

// Driver program
int main(void) {

    int usr;   // # of elements in array
    int *array; // data array

    printf("\nInsert the number of elements to create a random integer array in range [-10,10]: ");
    scanf("%d",&usr);
    
    if(usr < 2) {
        printf("\nInvalid input.Cannot create an array with less than 2 elements\nProgram will exit.\n");
        exit(0);
    }

    if(usr > INT_MAX) {
        printf("\nInvalid input.INT_MAX exceeded\nProgram will exit.\n");
        exit(0);
    }

    array = createArrayPosNeg(usr); // create random array
    printf("\nRandom integer array with %d elements in range [-10,10] created: ", usr);
    printArray(array, usr);  // print random array

    /* Dynamic Programming procedure */
    int max_sum = INT_MIN, tot_sum = 0;
    int low_idx = 0, high_idx = 0, i, j = 0;
    for(i = 0; i < usr; ++i) {
        tot_sum = tot_sum + array[i];
        if(tot_sum > max_sum) {
            max_sum = tot_sum;
            low_idx = j;
            high_idx = i;
        }
        /* if total_sum is negative, then if next number is negative
           next total_sum will be even less. If next number is positive,
           then the number itself will be greater than its sum with the negative tot_sum
        */
        if(tot_sum < 0) {
            tot_sum = 0;
            j = i + 1;
        }
    }
    printf("\nMaximum sum is between indexes %d and %d\n", low_idx, high_idx);
    printf("Maximum sum of subarray is %d\n", max_sum);
    printf("\n");
    free(array);
}