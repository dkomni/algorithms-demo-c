/*
 * BubbleSort Demonstration
 *
 * D. Komninos
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "utility.h"

// Bubble-Sort algorithm
/* NOTE: Algorithm runs in all cases in O(n^2)
It can be optimized by inserting a boolean flag
such that if no swap occurs in the inner loop
i.e the array is already sorted
the algorithm can stop, having best-case complexity O(n)
+ adaptive sorting */
void bubbleSort(int *array, int n, char opt) {

    int i, j;
    int swapped;

    for(i = 0; i < n-1; ++i) {
        swapped = 0;
        // Last i elements are already in place
        for(j = 0; j < n-i-1; ++j) {
            if(opt == 'd')  // descending sort
                if(array[j] < array[j+1]) {
                    swap(&array[j], &array[j+1]);
                    swapped = 1;
                }

            if(opt == 'a')  // ascending sort
                if(array[j] > array[j+1]) {
                    swap(&array[j], &array[j+1]);
                    swapped = 1;
                }
        }
        // If no elements were swapped by inner loop
        // array is already sorted
        if(swapped == 0)
            break;
    }
}

// Driver program
int main(void) {

    int usr;   // # of elements in array
    char opt;  // 'a' for ascending sort, 'd' for descending sort
    int *array;

    printf("\n\tBubble-Sort Demonstration\n");
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

    bubbleSort(array, usr, opt);  // sort using BubbleSort algorithm

    if(opt == 'a')
        printf("\nSorted array in ascending order: ");
    else
        printf("\nSorted array in descending order: ");

    printArray(array, usr);  // print sorted array
    free(array);    // free memory
    printf("\n");
}