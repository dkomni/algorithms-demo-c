/*
 * Header file for some simple utility functions
 * 
 * D. Komninos
 * 
 */

// Utility function for printing an array of integers of size n
void printArray(int *array, int n);

/* Utility function for creating an array
 * of integers in the range 1-100 of size n.
 * A pointer to the array is returned (to first element)
 */
int* createArray(int n);

/* Utility function for creating a sorted array of integers
 * in ascending order.
 * A pointer to the array is returned (to first element)
 */
int* createSortedAsc(int n);

/* Utility function for creating an array
 * of integers in the range [-10,10] of size n.
 * A pointer to the array is returned (to first element)
 */
int* createArrayPosNeg(int n);

// Utility function for swapping two integers
void swap(int *x, int *y);

// Utility function that returns maximum number between 2 integers
int max(int *x, int *y);

// Utility function that returns minimum number between 2 integers
int min(int *x, int *y);