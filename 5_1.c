// a. Insertion sort
#include <stdio.h>
void insertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);

    int i;
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
/*Insertion Sort Algorithm:
1. Start by assuming the first element in the array is sorted.
2. For each subsequent element in the array, compare it with the sorted portion of the array.
3. If the current element is smaller than an element in the sorted portion, shift all the elements that are greater than the current element one position to the right.
4. Insert the current element in the correct position in the sorted portion.
5. Repeat steps 2 to 4 until all the elements in the array are sorted.
*/