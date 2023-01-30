// c. Bubble sort
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
/* Here is an algorithm to implement bubble sort step by step:
1. Initialize the list and its length (‘n’).
2. Start the outer loop to traverse the list ‘n-1’ times.
3. Start the inner loop to traverse the list ‘n-i-1’ times, where ‘i’ is the current iteration of the outer loop.
4. Compare each pair of adjacent elements. If the left element is greater than the right element, swap them.
5. Continue the inner loop until all elements are compared and possibly swapped.
6. End the inner loop and move to the next iteration of the outer loop.
7. Continue the outer loop until all elements are compared and sorted.
8. Return the sorted list.
*/