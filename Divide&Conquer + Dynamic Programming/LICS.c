/* Divide&Conquer algorithm to find
 * the Longest Increasing Contiguous Subsequence (LICS) in an array in O(nlogn)
 * 
 * If array is sorted in ascending order, the whole array
 * is the LICS. If the array is sorted in descending order, then there is no LICS.
 * 
 * D. Komninos
 */
 
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "utility.h"

/* Additional function of the algorithm to find LICS
   on either side of middle index.

   Function returns an array of two elements, where
        arr[0] = MAX_LEFT_INDEX
        arr[1] = MAX_RIGHT_INDEX
*/
int *crossLICS(int *array, int start, int mid, int finish) {

    int *arr = malloc(sizeof(int)*2);
    
    int i;
    int low_idx = mid;   // assume first index of LICS on mid
    int high_idx = mid;  // assume last index of LICS on mid

    // process on the left of mid
    for(i = mid-1; i >= start; --i) {
        if(array[i] < array[low_idx])
            low_idx = i;
        else
            break;  // first index of LICS is set  
    }
    // process on the right of mid
    for(i = mid+1; i <= finish; ++i) {
        if(array[i] > array[high_idx])
            high_idx = i;
        else 
            break;  // last index of LICS is set
    }

    // low_idx and high_idx were not processed
    // i.e there is no increasing sequence on either side of mid
    if(low_idx == high_idx) {
        low_idx++;
        high_idx++;
    }

    arr[0] = low_idx;
    arr[1] = high_idx;
    return arr;
}

/* Main algorithm to find LICS in array[start...finish]

   Function returns an array of two elements, where
        arr[0] = MAX_LOW_INDEX
        arr[1] = MAX_HIGH_INDEX
*/
int *findLICS(int *array, int start, int finish) {

    int *arr = malloc(sizeof(int)*2);
    int *arr_left = malloc(sizeof(int)*2);
    int *arr_right = malloc(sizeof(int)*2);
    int *arr_cross;
    
    int mid;
    // Base case: one element
    if(start == finish) {
        arr[0] = start; 
        arr[1] = start;
        return arr;
    }

    mid = (start+finish)/2;

    arr_left = findLICS(array, start, mid);
    arr_right = findLICS(array, mid+1, finish);
    arr_cross = crossLICS(array, start, mid, finish);

    int numOfLeft = arr_left[1] - arr_left[0];
    int numOfRight = arr_right[1] - arr_right[0];
    int numOfCross = arr_cross[1] - arr_cross[0];

    if(numOfCross >= numOfLeft && numOfCross >= numOfRight) {
        free(arr_right);
        free(arr_left);
        free(arr);
        return arr_cross;
    }

    if(numOfRight >= numOfLeft && numOfRight >= numOfCross) {
        free(arr_left);
        free(arr_cross);
        free(arr);
        return arr_right;
    }

    free(arr_cross);
    free(arr_right);
    free(arr);
    return arr_left;
}

// Driver program
int main(void) {

    // array of two elements returned by findLICS
    int *aux_arr;

    int usr;   // # of elements in array
    int *array; // data array

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

    array = createArrayPosNeg(usr); // create random array
    printf("\nRandom integer array with %d elements in range [-10,10] created: ", usr);
    printArray(array, usr);  // print random array

    aux_arr = findLICS(array, 0, usr - 1);

    printf("\nLongest Increasing Contiguous Subsequence (LICS) is between indexes %d and %d with length %d\n", aux_arr[0], aux_arr[1], aux_arr[1]-aux_arr[0]);
    printf("\n");
    free(aux_arr);
    free(array);
}