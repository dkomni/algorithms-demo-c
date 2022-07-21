/*
 * HeapSort Demonstration
 *
 * D. Komninos
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "utility.h"

// Function to build a MaxHeap satisfying the heap property
// Heapify a subtree at node i (index in array)
// n is the size of the heap
void heapifyMax(int *array, int n, int i) {

    int max_index = i;          // root of subtree (parent)
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;

    // If left child is greater than parent
    if(leftChild < n && array[leftChild] > array[max_index])
        max_index = leftChild;

    // If right child is greater than the rest
    if(rightChild < n && array[rightChild] > array[max_index])
        max_index = rightChild;

    // If largest element is not root
    // maintain heap property
    if(max_index != i) {
        swap(&array[max_index],&array[i]);
        // recursively heapify the affected subtree at node max_index
        heapifyMax(array, n, max_index);
    }
}

// Function to build a MinHeap satisfying the heap property
// Heapify a subtree at node i (index in array)
// n is the size of the heap
void heapifyMin(int *array, int n, int i) {

    int min_index = i;          // root of subtree (parent)
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;

    // If left child is less than parent
    if(leftChild < n && array[leftChild] < array[min_index])
        min_index = leftChild;

    // If right child is less than the rest
    if(rightChild < n && array[rightChild] < array[min_index])
        min_index = rightChild;

    // If minimum element is not root
    // maintain heap property
    if(min_index != i) {
        swap(&array[min_index],&array[i]);
        // recursively heapify the affected subtree at node min_index
        heapifyMin(array, n, min_index);
    }
}

// HeapSort Algorithm
void heapSort(int *array, int n, char opt) {

    int i;
    
    // ascending sort
    if(opt == 'a') {
        // Build Max Heap (rearrange array)
        for(i = n/2 - 1; i >= 0; --i)
            heapifyMax(array, n, i);

        // One by one, extract an element from heap
        // At root, max element
        for(i = n-1; i > 0; --i) {
            // move current root to end
            swap(&array[0],&array[i]);
            // heapify the reduced heap
            heapifyMax(array, i, 0);
        }
    }
    // descending sort
    if(opt == 'd') {
        // Build Min Heap (rearrange array)
        for(i = n/2 - 1; i >= 0; --i)
            heapifyMin(array, n, i);

        // One by one, extract an element from heap
        // At root, min element
        for(i = n-1; i > 0; --i) {
            // move current root to end
            swap(&array[0],&array[i]);
            // heapify the reduced heap
            heapifyMin(array, i, 0);
        }
    }
}

// Driver program
int main(void) {

    int usr;   // # of elements in array
    char opt;  // 'a' for ascending sort, 'd' for descending sort
    int *array;

    printf("\n\tHeapSort Demonstration\n");
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

    heapSort(array, usr, opt);  // sort using HeapSort algorithm

    if(opt == 'a')
        printf("\nSorted array in ascending order: ");
    else
        printf("\nSorted array in descending order: ");

    printArray(array, usr);  // print sorted array
    free(array);    // free memory
    printf("\n");
}