/*
 * QuickSelect Demonstration
 *
 * D. Komninos
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "utility.h"

/* Standard partition procedure for an array. Last element is chosen 
   as the pivot (CLRS book presentation). All elements less than
   the pivot are on the left side of it and all elements greater
   than the pivot are on the right side of it. After this process, the pivot 
   element is in its right place in the sorted sequence. The index of the
   pivot is returned.

 * Better pivot finding strategies such as median of medians 
   results in linear worst-case time

 * Randomized pivot expects linear time on average (implemented below)
   and performs better when the array is already sorted or has equal elements

 * Lomuto's Partition Scheme

*/
int partition(int *array, int start, int finish) {

    int pivot = array[finish];  // last element as pivot
    int i = start - 1;          // index of smaller or greater element (depends on sorting order)
    int j;

    for(j = start; j < finish; ++j) {
                // if current element is smaller than pivot
                if(array[j] < pivot) {
                    i++;    // increment index of smaller element
                    swap(&array[i], &array[j]);
                }
    }
    swap(&array[i+1], &array[finish]);  // place pivot in its correct position in sorted array
    return(i+1);    // return index of pivot in array
}

// function to choose a random pivot index
// element at pivot index is swapped with last element
// after, standard Lomuto's partition scheme is utilized
int randomPivot(int *array, int start, int finish) {
    // generate random index between start and finish
    int pivot_idx = (rand() % (finish-start+1)) + start;
    // swap pivot element with last element
    swap(&array[pivot_idx], &array[finish]);
    // call standard partition scheme
    return partition(array, start, finish);
}

// quickSelect algorithm to find the k-th order statistic
// using partition() procedure like quickSort but choosing a random pivot (expected O(n))
// input k here represents the index of the k-th order statistic if the array was sorted
// so, if we want to find k-th order statistic, feed this input with k - 1 (as in main function below)
int quickSelect(int *array, int start, int finish, int k) {

    int pivot_idx;

    if(start > finish)
        return 0;
    else {
        // place pivot in position (like quicksort)
        pivot_idx = randomPivot(array, start, finish);

        // k-th order statistic is the pivot
        if(pivot_idx == k) 
            return array[pivot_idx];
        // k-th smallest element is on the left side of current pivot
        if(k < pivot_idx)
            return quickSelect(array, start, pivot_idx-1, k);
        // k-th smallest element is on the right side of current pivot
        if(k > pivot_idx)
            return quickSelect(array, pivot_idx+1, finish, k);
    }
}

// Driver program
int main(void) {

    int usr;           // # of elements in array
    int usr_k;        // k-th smallest given by user
    int kthSmallest;  // k-th order statistic returned by quickSelect
    int *array;

    printf("\n\tQuickSelect Demonstration\n");
    printf("\nInsert the number of elements to create a random integer array: ");
    scanf("%d",&usr);
    
    if(usr < 1) {
        printf("\nInvalid input.Cannot create an array with less than 1 element\nProgram will exit.\n\n");
        exit(0);
    }

    if(usr > INT_MAX) {
        printf("\nInvalid input.INT_MAX exceeded\nProgram will exit.\n\n");
        exit(0);
    }

    array = createArray(usr); // create random array
    printf("\nRandom integer array with %d elements in range 1-100 created: ", usr);
    printArray(array, usr);  // print random array
    
    while(1) {
        printf("\nChoose the k-th order statistic: ");
        scanf("%d", &usr_k);
        if(usr_k < 1 || usr_k > usr) 
            printf("Invalid input. k out of bounds\n");
        else
            break;
    }

    kthSmallest = quickSelect(array, 0, usr-1, usr_k-1);
    printf("\nk-th order statistic: %d\n", kthSmallest);

    free(array);    // free memory
    printf("\n");
}