// Perform Linear Search and Binary Search on an array 
#include <stdio.h> 
#include <stdlib.h> 
// Function to implement linear search 
int linearSearch(int arr[], int n, int x){ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
// Function to implement binary search 
int binarySearch(int arr[], int l, int r, int x){ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 

        // If the element is present at the middle 
        if (arr[mid] == x) 
            return mid; 

        // If the element is smaller than mid 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 

        // Else the element is in right subarray 
        return binarySearch(arr, mid + 1, r, x); 
    } 
    // Element is not present in the array 
    return -1; 
} 
// Driver program to test above functions 
int main(){ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 4; 
    int result; 

    // Linear search 
    result = linearSearch(arr, n, x); 
    printf("Linear Search-> "); 
    if (result == -1) 
        printf("Element is not present in the array\n"); 
    else
        printf("Element is present at index %d\n", result); 

    // Binary search 
    result = binarySearch(arr, 0, n - 1, x); 
    printf("Binary Search-> "); 
    if (result == -1) 
        printf("Element is not present in the array\n"); 
    else
        printf("Element is present at index %d\n", result); 

    return 0; 
} 

/* Algorithm
Linear Search Algorithm:
1.	Start by setting a variable, i, to 0.
2.	Check if the value of the current element in the array is equal to the target value.
3.	If it is equal, return the index i.
4.	If it is not equal, increment i and repeat step 2.
5.	If the end of the array is reached and the target value has not been found, return -1 to indicate that the target value was not found.
Binary Search Algorithm:
1.	Start by setting variables, left and right, to the indices of the first and last elements in the array, respectively.
2.	Calculate the middle index by taking the average of left and right indices.
3.	Check if the value of the current element in the array is equal to the target value.
4.	If it is equal, return the index of the middle element.
5.	If it is less than the target value, set left to the middle index + 1. Repeat steps 2 to 4.
6.	If it is greater than the target value, set right to the middle index - 1. Repeat steps 2 to 4.
7.	If the left index becomes greater than the right index, return -1 to indicate that the target value was not found.
*/
