# algorithms-demo-c
Demonstration of various algorithms in C language and solutions to some common problems in Computer Science using *Divide&amp;Conquer* (D&Q) and *Dynamic Programming* (DP).

Every folder contains *utility.c* and *utility.h* files, where some basic functions are implemented for demonstration purposes like creating arrays, swapping values, find min-max values e.t.c. Detailed comments may be found inside the code. Also, a pdf file is included with the basic properties involving the sorting algorithms. *utility.c* MUST be compiled along with the desired source file. An example is shown in the end here.

## Sorting
Folder contains implementation of **BubbleSort**, **HeapSort**, **InsertionSort**, **SelectionSort**, **MergeSort** and **QuickSort** algorithms. The main function in each file may be modified in order to test various examples and select ascending or descending sorting. Detailed comments may be found inside the code about the implementation, as well as some information regarding time and space complexity of different solutions and approaches.

## Divide&amp;Conquer, Dynamic Programming (DP)
Here, we deal with some famous problems in Computer Science and give solutions using D&Q and DP techniques. As before, one may find detailed information inside the code. The problems we are dealing with include

- *Find if there is an index i in a sorted array, such that it is equal to the element in that position, i.e array(i) = i*
   - Solved using **BinarySearch**

- *Count the inversions in an unsorted array*
   - Solved with a modified version of **MergeSort**
   
- *Find the n-th Fibonacci number*
   - Solved by calculating the powers of the Fibonacci matrix with D&Q
   
- *Find the Longest Increasing Contiguous Subsequence (LICS) in an array*
   - Solved with a modified version of **BinarySearch** in *LICS.c*, as well as with DP in *LICS_DP.c*
   
- *Find the subarray with the maximum sum in a given array*
   - Solved using D&Q in *maxSubArraySum.c* and DP (*Kadane's algorithm*) in *maxSubArraySum_DP.c*
   
- *Calculate 2 to the power of n*
   - Solved using D&Q technique
   
- *Given two arrays of size n sorted in ascending order, find the median of the 2n numbers in O(logn)*
   - Solved using a modified version of **BinarySearch**
   
- *Find the k-th order statistic using **QuickSelect** algorithm*
   - Different partition schemes may be used here, see inside the code for detailed information
                    
## Remarks
The code provided here is mainly for educational, as well as demonstration purposes in order to dive into the study of algorithms and compare various techniques that are present in computer science. I wrote this code when I was studying algorithms myself as it is a subject that amazes me up to this day. Of course, nowadays there are efficient and optimized built-in implementations in various libraries of different programming languages. However, any computer scientist must know what is *'inside the box'*, rather than using it as it is.

The book I followed for the implementation is the famous *'Introduction to Algorithms, 2nd Edition'* by *Cormen, Leiserson, Rivest and Stein* (CLRS).

Compile the source code and then run the executables. I always use the latest *gcc* version on a Linux machine.

e.g compile *LICS.c* and *utility.c* and name the executable as *LICSexe*
```
gcc -o LICSexe LICS.c utility.c
./LICSexe
```
