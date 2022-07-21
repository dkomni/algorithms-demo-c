/*
 * Binary Search demonstration (Divide&Conquer) algorithm
 * 
 * Simple linear search takes O(n) time
 * With Divide&Conquer technique, binary search takes O(logn) time
 * 
 * The program below creates a sorted array in ascending order
 * and uses binary search algorithm to determine if there is an index i
 * in the array such that array[i] = i
 * 
 * D. Komninos
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "utility.h"

// Binary search implementation
// Determine if there is an index i in the array such that array[i] = i
int binarySearch(int *array, int start, int finish) {
    
    if(start < finish) {
        int mid = (start+finish)/2;
        // if index mid is equal to the element in that index, return it
        if(mid == array[mid])
            return mid;
        // if index mid is less than the element in that index
        // search to the left because mid will be less on the right side for every element
        if(mid < array[mid])
            return binarySearch(array, start, mid);
        // same logic here on the right
        if(mid > array[mid])
            return binarySearch(array, mid+1, finish);
    }
    // if we reach here, there is no such index
    return -1;
}

// function to compare two elements of an array
// used by qsort() from stdlib
int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Driver code
int main(void) {

    int usr;    // # of elements in array
    int *array; // data array

    printf("\nInsert the number of elements to create a random integer sorted array in ascending order: ");
    scanf("%d", &usr);
    
    if(usr < 2) {
        printf("\nInvalid input.Cannot create an array with less than 2 elements\nProgram will exit.\n");
        exit(0);
    }

    if(usr > INT_MAX) {
        printf("\nInvalid input.INT_MAX exceeded\nProgram will exit.\n");
        exit(0);
    }

    array = createArray(usr);                // create random array
    qsort(array, usr, sizeof(int), cmpfunc); // sort array with in-built quicksort
    printf("\nRandom integer sorted array with %d elements created: ", usr);
    printArray(array, usr);      // print random array

    int index = binarySearch(array, 0, usr-1);

    if(index == -1)
        printf("\nNo index i in array is equal to the element in that index");
    else
        printf("\nThere is an index i = %d such that is equal to the element: array[%d] = %d\n", index, index, index);
    
    free(array);    // free memory
    printf("\n");
}