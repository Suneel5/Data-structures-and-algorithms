#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int i, j, key;
    // Loop for iteration or pass
    for (i = 1; i < n; i++) { // 1 to n-1
        key = arr[i];
        j = i - 1;

        // Finding position for insertion in sorted array
        while (j >= 0 && arr[j] > key) { // key is smaller than element at pos j
            arr[j + 1] = arr[j]; // Shifting element at j to j+1, now j is vacant
            j = j - 1;
        }
        arr[j + 1] = key; // Inserting key element at position j+1 as element at j is lesser than key
    }
}

int main() {
    int arr[] = {0, 4, 3, 6, 1, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
