/*
 * Dynamic Programming algorithm to find the 
 * Longest Increasing Contiguous Subsequence (LICS) in an array
 * 
 * Obvious is to use two nested loops resulting in quadratic complexity.
 * 
 * With Divide&Conquer technique, we will achieve O(nlogn) time complexity.
 * 
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

    int usr;     // # of elements in array
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
    int low_idx = 0, high_idx = 0;  // first and last index of LICS (primary)
    int low_tmp = 0, high_tmp = 0;  // temporary first and last index of another LICS for comparison

    for(int i = 1; i < usr; ++i) {
        // priority to primary index
        if(array[i] >= array[high_idx] && high_idx >= high_tmp && low_idx <= low_tmp)
            high_idx++;  
        else if(array[i] >= array[high_tmp] && high_idx <= high_tmp && low_idx <= low_tmp)
            high_tmp++;
        else {  // another LICS with greater length may occur
            low_tmp = i;
            high_tmp = i;
        }
        // found a sequence with greater length
        if(high_tmp - low_tmp >= high_idx - low_idx) {
            low_idx = low_tmp;
            high_idx = high_tmp;
        } else if(high_idx - low_idx >= high_tmp - low_tmp) {
            low_tmp = i;
            high_tmp = i;
        }
    }
    // array was sorted in descending order
    // LICS is the last element with length 0
    if(high_idx >= usr-1 && low_idx >= usr-1 && low_tmp >= usr-1 && high_tmp >= usr-1) {
            low_idx = usr-1;
            high_idx = usr-1;
    }
    printf("\nLongest Increasing Contiguous Subsequence (LICS) is between indexes %d and %d with length %d\n", low_idx, high_idx, high_idx-low_idx);
    printf("\n");
    free(array);
}