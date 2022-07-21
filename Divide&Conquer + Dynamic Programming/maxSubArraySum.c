/*
 * Divide&Conquer algorithm to find the subarray with the maximum
 * sum in an array.
 * 
 * Obvious is to use two nested loops resulting in quadratic complexity.
 * 
 * With Divide&Conquer technique, we will achieve O(nlogn) time complexity.
 * Moreover, with Dynamic Programming (Kadane's algorithm), linear time
 * complexity can be achieved (O(n)). However, this is a demonstration of the power
 * of Divide&Conquer technique over obvious solutions.
 * 
 * D. Komninos
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "utility.h"

/* Additional function of the algorithm to find maximum sum
   on either side of middle index.

   Function returns an array of three elements, where
        arr[0] = MAX_LEFT_INDEX
        arr[1] = MAX_RIGHT_INDEX
        arr[2] = MAX_CROSS_SUM
*/
int *maxCrossingSum(int *array, int start, int mid, int finish) {

    int *arr = malloc(sizeof(int)*3);
    
    int left_sum, right_sum, sum, i;

    // process on the left side of middle
    left_sum = INT_MIN;
    sum = 0;
    for(i = mid; i >= start; --i) {
        sum = sum + array[i];
        if(sum > left_sum) {
            left_sum = sum;
            arr[0] = i;
        }
    }
    // process on the right side of middle
    right_sum = INT_MIN;
    sum = 0;
    for(i = mid + 1; i <= finish; ++i) {
        sum = sum + array[i];
        if(sum > right_sum) {
            right_sum = sum;
            arr[1] = i;
        }
    }
    // store the sum of either side of mid
    arr[2] = left_sum + right_sum;

    return arr;
}

/* Main algorithm to find maximum subarray sum in array[start...finish]

   Function returns an array of three elements, where
        arr[0] = MAX_LOW_INDEX
        arr[1] = MAX_HIGH_INDEX
        arr[2] = MAX_SUM
*/
int *maxSubArraySum(int *array, int start, int finish) {

    int *arr = malloc(sizeof(int)*3);
    int *arr_left = malloc(sizeof(int)*3);
    int *arr_right = malloc(sizeof(int)*3);
    int *arr_cross;
    
    int mid;
    // Base case: one element
    if(start == finish) {
        arr[0] = start; 
        arr[1] = start;
        arr[2] = array[start];
        return arr;
    }

    mid = (start+finish)/2;

    arr_left = maxSubArraySum(array, start, mid);
    arr_right = maxSubArraySum(array, mid+1, finish);
    arr_cross = maxCrossingSum(array, start, mid, finish);

    if(arr_cross[2] >= arr_left[2] && arr_cross[2] >= arr_right[2]) {
        free(arr_left);
        free(arr_right);
        free(arr);
        return arr_cross;
    }

    if(arr_right[2] >= arr_left[2] && arr_right[2] >= arr_cross[2]) {
        free(arr_left);
        free(arr_cross);
        free(arr);
        return arr_right;
    }

    free(arr_right);
    free(arr_cross);
    free(arr);
    return arr_left;
}

// Driver program
int main(void) {

    // array of three elements returned by maxSubArraySum
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

    aux_arr = maxSubArraySum(array, 0, usr - 1);

    printf("\nMaximum sum is between indexes %d and %d\n", aux_arr[0], aux_arr[1]);
    printf("Maximum sum of subarray is %d\n", aux_arr[2]);
    printf("\n");
    free(aux_arr);
    free(array);
}