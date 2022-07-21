/*
 * InsertionSort Demonstration
 *
 * D. Komninos
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "utility.h"

// Insertion-Sort Algorithm
/* NOTE: instead of simple swap between the key and the pre-sorted values
the key is placed directly to its position by only one assignment in the inner loop.
A recursive function can also be implemented but it is worse than this approach
because O(n) space will be needed instead of O(1).
Execution time is NOT reduced with recursion */
void insertionSort(int *array, int n, char opt) {

    int i, j, key;

    for(i = 1; i < n; ++i) {
        key = array[i];
        j = i-1;
        
        /* Move elements of array[0..i-1], that are 
          greater than key, to one position ahead 
          of their current position */
        // ascending sort
        if(opt == 'a') {
            while(j >= 0 && array[j] > key) {
                array[j+1] = array[j];
                j = j-1;
            }
            array[j+1] = key;
        }

        // descending sort
        if(opt == 'd') {
            while(j >= 0 && array[j] < key) {
                array[j+1] = array[j];
                j = j-1;
            }
            array[j+1] = key;
        }
    }
}

// Driver program
int main(void) {

    int usr;   // # of elements in array
    char opt;  // 'a' for ascending sort, 'd' for descending sort
    int *array;

    printf("\n\tInsertion-Sort Demonstration\n");
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

    insertionSort(array, usr, opt);  // sort using InsertionSort algorithm

    if(opt == 'a')
        printf("\nSorted array in ascending order: ");
    else
        printf("\nSorted array in descending order: ");

    printArray(array, usr);  // print sorted array
    free(array);    // free memory
    printf("\n");
}