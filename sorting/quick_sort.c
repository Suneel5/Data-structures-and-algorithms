#include <stdio.h>

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        // Find element greater than pivot
        while (i <= high && arr[i] <= pivot) {
            i++;
        }

        // Find element lesser than pivot
        while (arr[j] > pivot) {
            j--;
        }

        // Swap elements greater than and lesser than pivot
        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else {
            break;
        }
    }

    // Swap pivot with element at index j
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j; // Return the pivot index
}

// Function to perform quicksort
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quicksort(arr, low, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, high);
    }
}

int main() {
    int arr[] = {15, 20, 55, 8, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
