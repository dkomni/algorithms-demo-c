/*
 * QuickSort Demonstration
 *
 * D. Komninos
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "utility.h"

/* Partition() procedure for an array. Last element is chosen 
   as the pivot (CLRS book presentation). All elements less than
   the pivot are on the left side of it and all elements greater
   than the pivot are on the right side of it. After this process, the pivot 
   element is in its right place in the sorted sequence. The index of the
   pivot is returned.

   Lamuto's Partition Scheme
*/
int partition(int *array, int start, int finish, int opt) {

    int pivot = array[finish];  // last element as pivot
    int i = start - 1;          // index of smaller or greater element (depends on sorting order)
    int j;

    for(j = start; j < finish; ++j) {
            // ascending order
            if(opt == 'a')
                // if current element is smaller than pivot
                if(array[j] < pivot) {
                    i++;    // increment index of smaller element
                    swap(&array[i], &array[j]);
                }

            // descending order
            if(opt == 'd')
                // if current element is greater than pivot
                if(array[j] > pivot) {
                    i++;    // increment index of greater element
                    swap(&array[i], &array[j]);
                }
    }
    swap(&array[i+1], &array[finish]);  // place pivot in its correct position in sorted array
    return(i+1);    // return index of pivot in array
}

/* 3-Way Partitioning as described by E. W. Dijkstra
 * for the solution of Dutch national flag probem
 * 
 * This partition scheme deals with arrays with redundant elements and
 * leading the best-case scenario to O(n) instead of O(nlogn) if there are
 * O(1) unique elements.
 * 
 * Elements less than the pivot are placed before it, those equal to the pivot are placed on their
 * respective position as if the array was already sorted and those greater than the pivot are placed
 * after it.
 * 
 */
int three_way_partition(int *array, int start, int finish, int opt) {
    // pivot element
    int pivot = array[finish];
    // index of smaller or greater element (depends on sorting order) on the left
    int i = start - 1;
    // index of smaller or greater element (depends on sorting order) on the right
    int k = finish + 1;
    // processing index
    int j = start;

    // handle array consisting of two elements
    if(finish - start <= 1) {
        // ascending sort
        if(opt == 'a')
            if(array[start] > array[finish]) {
                swap(&array[start], &array[finish]);
                return start;
            } else
                return finish;

        // descending sort
        if(opt == 'd')
            if(array[start] < array[finish]) {
                swap(&array[start], &array[finish]);
                return start;
            } else
                return finish;
    }
    
    while(j < k) {
        // ascending sort
        if(opt == 'a')
            if(array[j] < pivot) {
                i++;
                swap(&array[i], &array[j]);
                j++;
            } else if(array[j] > pivot) {
                k--;
                swap(&array[k], &array[j]);
            } else
                j++;

        // descending sort
        if(opt == 'd')
            if(array[j] > pivot) {
                i++;
                swap(&array[i], &array[j]);
                j++;
            } else if(array[j] < pivot) {
                k--;
                swap(&array[k], &array[j]);
            } else
                j++;
    }
    return(i+1);
}

// function to choose a random pivot index
// element at pivot index is swapped with last element
// after, standard Lomuto's partition scheme is utilized
int randomPivot(int *array, int start, int finish, int opt) {
    // generate random index between start and finish
    int pivot_idx = (rand() % (finish-start+1)) + start;
    // swap pivot element with last element
    swap(&array[pivot_idx], &array[finish]);
    // call 3-way partition scheme
    return three_way_partition(array, start, finish, opt);
}

// QuickSort algorithm (3-way randomized)
void quickSort(int *array, int start, int finish, int opt) {

    int pivot_idx;  // pivot index returned by partition() procedure

    if(start < finish) {
        // find pivot and place it in position - standard partition procedure
        // pivot_idx = partition(array, start, finish, opt);
        
        /* Random pivot index selection between start and finish
         * to improve expected complexity to O(nlogn)
         * 
         * After, 3-way partition scheme takes place
         * for better handling of arrays with redundant elements
         */ 
        pivot_idx = randomPivot(array, start, finish, opt);
        
        /* 3-Way QuickSort with O(n) best-case scenario */
        // sort elements before pivot
        quickSort(array, start, pivot_idx-1, opt);
        // sort elements after pivot
        quickSort(array, pivot_idx+1, finish, opt);
    }
}

// Driver program
int main(void) {

    int usr;   // # of elements in array
    char opt;  // 'a' for ascending sort, 'd' for descending sort
    int *array;

    printf("\n\tQuickSort Demonstration\n");
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

    quickSort(array, 0, usr-1, opt);  // sort using QuickSort algorithm

    if(opt == 'a')
        printf("\nSorted array in ascending order: ");
    else
        printf("\nSorted array in descending order: ");

    printArray(array, usr);  // print sorted array
    free(array);    // free memory
    printf("\n");
}