/*
 * Divide&Conquer Algorithm to count number of inversions
 * in an unsorted array
 * 
 * Obvious iterative algorithm requires two nested loops, so complexity
 * is quadratic. However, we can use a modified mergeSort with merge()
 * as the key function and achieve O(nlogn) time complexity.
 *
 * The number of inversions is a metric of "how much" sorted an array is
 * (either ascending or descending depending on utilization). For example, if
 * the number of inversions is zero, that means the array is completely sorted.
 * 
 * Here, code is implemented
 * for ascending sort but can be modified easily for descending too.
 * 
 * D. Komninos
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "utility.h"

// merge procedure to merge two sorted arrays
// into one sorted array like in mergeSort
// Here, the number of inversions is returned
int mergeNcount(int *array, int start, int mid, int finish) {

    int n1 = mid - start + 1;   // size of left subarray
    int n2 = finish - mid;      // size of right subarray
    int i, j, k;
    int numOfInversions = 0;

    /* Below implementation modifies the input array.
       In case we didn't want to edit it and use +O(n) space by just copying it
       (merge needs O(n) of auxiliary space to work + O(n) the copy of initial array),
       we just treat the array as whole LEFT, RIGHT and insert elements at auxiliary memory.
    */
    // auxiliary temporary arrays
    int LEFT[n1], RIGHT[n2];
    // copy data to temporary arrays
    for(i = 0; i < n1; ++i)
        LEFT[i] = array[start + i];
    for(j = 0; j < n2; ++j)
        RIGHT[j] = array[mid + 1 + j];

    i = 0;      // start index of left subarray
    j = 0;      // start index of right subarray
    k = start;  // start index of merged subarray

    while(i < n1 && j < n2) { 
        if(LEFT[i] <= RIGHT[j]) {
            array[k] = LEFT[i];
            i++;
        } else {
            array[k] = RIGHT[j];
            j++;
            numOfInversions = numOfInversions + n1 - i;
        }
        k++;
    }

    // copy the remaining elements of left subarray if any
    while(i < n1) 
        array[k++] = LEFT[i++];

    // copy the remaining elements of right subarray if any
    while(j < n2) 
        array[k++] = RIGHT[j++];

    return numOfInversions;
}

// count the inversions with Divide&Conquer
int countInversions(int *array, int start, int finish) {

    int mid, tot_inv = 0;
    if(start < finish) {
        mid = (start+finish)/2;
        tot_inv += countInversions(array, start, mid);
        tot_inv += countInversions(array, mid + 1, finish);
        tot_inv += mergeNcount(array, start, mid, finish);
    }
    return tot_inv;
}

// Driver program
int main(void) {

    int usr;   // # of elements in array
    int *array;

    printf("\nInsert the number of elements to create a random integer array: ");
    scanf("%d",&usr);
    
    if(usr < 2) {
        printf("\nInvalid input.Cannot create an array with less than 2 elements\nProgram will exit.\n");
        exit(0);
    }

    if(usr > INT_MAX) {
        printf("\nInvalid input.INT_MAX exceeded\nProgram will exit.\n");
        exit(0);
    }

    array = createArray(usr); // create random array
    printf("\nRandom integer array with %d elements in range 1-100 created: ", usr);
    printArray(array, usr);  // print random array

    printf("\nNumber of inversions in array: %d\n", countInversions(array, 0, usr-1));
    
    free(array);    // free memory
    printf("\n");
}