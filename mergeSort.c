#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int right[], int leftSize, int rightSize) {
    int i = 0, j = 0, k = 0;

    // Merge the left and right arrays
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // Copy any remaining elements of left[]
    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    // Copy any remaining elements of right[]
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int n) {
    if (n < 2) return;  // Base case: if the array size is less than 2, it's already sorted

    int middle = n / 2;
    
    // Dynamically allocate memory for the left and right subarrays
    int *left = (int*)malloc(middle * sizeof(int));
    int *right = (int*)malloc((n - middle) * sizeof(int));

    // Copy data to the left and right subarrays
    for (int i = 0; i < middle; i++) left[i] = arr[i];
    for (int i = middle; i < n; i++) right[i - middle] = arr[i];

    // Recursive calls to sort the subarrays
    mergeSort(left, middle);
    mergeSort(right, n - middle);

    // Merge the sorted subarrays
    merge(arr, left, right, middle, n - middle);

    // Free the dynamically allocated memory
    free(left);
    free(right);
}

int main() {
    int arr[] = {10, 3, 23, 7, 9, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
