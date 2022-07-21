/*
 * MergeSort Demonstration
 *
 * D. Komninos
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "utility.h"

// merge procedure to merge two sorted arrays
// into one sorted array
void merge(int *array, int start, int mid, int finish, int opt) {

    int n1 = mid - start + 1;   // size of left subarray
    int n2 = finish - mid;      // size of right subarray
    int i, j, k;

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
        // ascending sort
        if(opt == 'a') {
            if(LEFT[i] <= RIGHT[j]) {
                array[k] = LEFT[i];
                i++;
            } else {
                array[k] = RIGHT[j];
                j++;
            }
        }
        // descending sort
        if(opt == 'd') {
            if(LEFT[i] > RIGHT[j]) {
                array[k] = LEFT[i];
                i++;
            } else {
                array[k] = RIGHT[j];
                j++;
            }
        }
        k++;
    }

    // copy the remaining elements of left subarray if any
    while(i < n1) 
        array[k++] = LEFT[i++];

    // copy the remaining elements of right subarray if any
    while(j < n2) 
        array[k++] = RIGHT[j++];
}

// MergeSort Algorithm
void mergeSort(int *array, int start, int finish, int opt) {

    int mid;    // middle index

    if(start < finish) {
        mid = (start+finish)/2;
        // sort first half(left)
        mergeSort(array, start, mid, opt);
        // sort second half(right)
        mergeSort(array, mid+1, finish, opt);
        // merge the two halves
        merge(array, start, mid, finish, opt);
    }
}

// Driver program
int main(void) {

    int usr;   // # of elements in array
    char opt;  // 'a' for ascending sort, 'd' for descending sort
    int *array;

    printf("\n\tMergeSort Demonstration\n");
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
    
    while(1) {
        printf("\nChoose \'a\' for ascending sort or \'d\' for descending: ");
        scanf(" %c", &opt);
        getchar();
        if(opt != 'a' && opt != 'd') 
            printf("Invalid input.");
        else
            break;
    }

    mergeSort(array, 0, usr-1, opt);  // sort using MergeSort algorithm

    if(opt == 'a')
        printf("\nSorted array in ascending order: ");
    else
        printf("\nSorted array in descending order: ");

    printArray(array, usr);  // print sorted array
    free(array);    // free memory
    printf("\n");
}