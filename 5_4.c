// d. Selection sort
#include <stdio.h>
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
/* Here is an algorithm to implement selection sort step by step:
1. Initialize the list and its length (‘n’).
2. Start the outer loop to traverse the list ‘n-1’ times.
3. In each iteration of the outer loop, set ‘minIndex’ to the current iteration index ‘i’.
4. Start the inner loop to traverse the sub-list from ‘i+1’ to ‘n-1’ to find the minimum element.
5. Compare each element with the current minimum element. If an element is smaller than the current minimum, update the ‘minIndex’ with the index of that element.
6. If ‘minIndex’ is not equal to ‘i', swap the minimum element with the current element.
7. End the inner loop and move to the next iteration of the outer loop.
8. Continue the outer loop until all elements are compared and sorted.
9. Return the sorted list.
*/