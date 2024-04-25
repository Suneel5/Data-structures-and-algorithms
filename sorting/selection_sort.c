#include <stdio.h>
#include<stdlib.h>
void selection_sort(int arr[], int n) {
     int i, j, indexmin, temp;
    // Loop iteration or pass
    for ( i = 0; i < n; i++) {
        int indexmin = i;
        // Loop for finding the minimum element from the remaining unsorted list
        for ( j = i + 1; j < n; j++) {
            if (arr[j] < arr[indexmin]) {
                indexmin = j;
            }
        }
        // Swap element at i and the minimum element so the minimum element is at position i
        int temp = arr[i];
        arr[i] = arr[indexmin];
        arr[indexmin] = temp;
    }
}

int main() {
    int i;
    int arr[] = {3, 8, 4, 1, 9, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, n);

    printf("Sorted array: ");
    for ( i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
