/*
 * Implementation of some simple utility functions for testing algorithms
 * 
 * D. Komninos
 * 
 */

#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Utility function to print an array of size n
void printArray(int *array, int n) {

    int i;

    for(i = 0; i < n; ++i)
        printf("%d ", array[i]);

    printf("\n");
}

// Function to create random array of integers in range [1,100]
int* createArray(int n) {

    int i;
    int *array;

    array = (int*)malloc(sizeof(*array)*n);

    srand(time(0));

    for(i = 0; i < n; ++i)
        array[i] = (rand() % (100)) + 1;

    return array;
}

// Function to create random sorted array of integers in ascending order
int* createSortedAsc(int n) {

    int i;
    int *array;

    array = (int*)malloc(sizeof(*array)*n);
    
    srand(time(0));

    for(i = 0; i < n; ++i)
        array[i] = (rand() % 2) + i*2;

    return array;
}

// Function to create random array of integers in range [-10,10]
int* createArrayPosNeg(int n) {

    int i;
    int *array;

    array = (int*)malloc(sizeof(*array)*n);
    
    srand(time(0));

    for(i = 0; i < n; ++i)
        array[i] = ((rand() % (21))) - 10;

    return array;
}

// Utility function to swap 2 integers
void swap(int *x, int *y) {

    int temp = *x;

    *x = *y;
    *y = temp;
}

// Utility function that returns maximum number between 2 integers
int max(int *x, int *y) {

    if(*x >= *y)
        return *x;
    return *y;
}

// Utility function that returns minimum number between 2 integers
int min(int *x, int *y) {

    if(*x <= *y)
        return *x;
    return *y;
}