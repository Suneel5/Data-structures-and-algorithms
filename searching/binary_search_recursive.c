#include <stdio.h>

int binary_search(int arr[], int low, int high, int num) {
    if (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == num)
            return mid;
        else if (num < arr[mid])
            return binary_search(arr, low, mid - 1, num); // Search in left subarray
        else
            return binary_search(arr, mid + 1, high, num); // Search in right subarray
    }
    return -1; // Element not found
}

int main() {
    int index, num, size;
    int arr[] = {1, 2, 3, 4, 5};
    size = sizeof(arr) / sizeof(arr[0]);
    num = 4;
    index = binary_search(arr, 0, size - 1, num); // Initial call to binary_search
    if (index != -1)
        printf("Given number %d is found at position %d\n", num, index + 1);
    else
        printf("Given number %d is not found in the array\n", num);
    
    return 0;
}
