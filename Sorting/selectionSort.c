/*
 * SelectionSort Demonstration
 *
 * D. Komninos
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "utility.h"

// Selection-Sort Algorithm (optimized for stability)
void selectionSort(int *array, int n, char opt) {

    int i, j, min_idx, max_idx, key;

    for(i = 0; i < n-1; ++i) {
        // ascending order
        if(opt == 'a') {
            // find minimum in unsorted subarray
            min_idx = i;
            for(j = i+1; j < n; ++j) 
                if(array[j] < array[min_idx])
                    min_idx = j;

            // swap(&array[min_idx], &array[i]);  // not stable

            /* Move minimum at current i and by shifting forward the rest of
               the elements, stability is maintained (instead of swapping) */
            key = array[min_idx];
            while(min_idx > i) {
                array[min_idx] = array[min_idx-1];
                min_idx--;
            }
            array[i] = key;
        }

        // decending order
        if(opt == 'd') {
            // find maximum in unsorted subarray
            max_idx = i;
            for(j = i+1; j < n; ++j) 
                if(array[j] > array[max_idx])
                    max_idx = j;

            // swap(&array[max_idx], &array[i]);

            /* Move maximum at current i and by shifting forward the rest of
               the elements, stability is maintained (instead of swapping) */
            key = array[max_idx];
            while(max_idx > i) {
                array[max_idx] = array[max_idx-1];
                max_idx--;
            }
            array[i] = key;
        }
    }
}

// Driver program
int main(void) {

    int usr;   // # of elements in array
    char opt;  // 'a' for ascending sort, 'd' for descending sort
    int *array;

    printf("\n\tSelection-Sort Demonstration\n");
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

    selectionSort(array, usr, opt);  // sort using SelectionSort algorithm

    if(opt == 'a')
        printf("\nSorted array in ascending order: ");
    else
        printf("\nSorted array in descending order: ");

    printArray(array, usr);  // print sorted array
    free(array);    // free memory
    printf("\n");
}