def merge(arr, low, mid, high):
    """
    Merges two sorted sub-arrays of a given array.

    Args:
        arr: The array containing the sub-arrays to be merged.
        low: The starting index of the left sub-array.
        mid: The index separating the left and right sub-arrays.
        high: The ending index of the right sub-array.

    Returns:
        None (modifies the original array 'arr' in-place).
    """

    left_size = mid - low + 1  # Size of left sub-array
    right_size = high - mid  # Size of right sub-array

    # Create temporary arrays for the sub-arrays
    left = [0] * left_size
    right = [0] * right_size

    # Copy data to temporary arrays
    for i in range(left_size):
        left[i] = arr[low + i]
    for j in range(right_size):
        right[j] = arr[mid + 1 + j]  # + 1 to skip the middle element

    i, j, k = 0, 0, low  # Indices for left, right, and merged arrays

    # Merge the sub-arrays back into arr[low..high]
    while i < left_size and j < right_size:
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    # Copy remaining elements of left or right sub-array
    while i < left_size:
        arr[k] = left[i]
        i += 1
        k += 1
    while j < right_size:
        arr[k] = right[j]
        j += 1
        k += 1


def merge_sort(arr, low, high):
    """
    Implements the merge sort algorithm to sort an array in ascending order.

    Args:
        arr: The array to be sorted.
        low: The starting index of the sub-array to be sorted.
        high: The ending index of the sub-array to be sorted.

    Returns:
        None (modifies the original array 'arr' in-place).
    """

    if low < high:
        mid = (low + high) // 2  # Avoid integer overflow

        # Sort the first and second halves (recursively)
        merge_sort(arr, low, mid)
        merge_sort(arr, mid + 1, high)

        # Merge the sorted halves
        merge(arr, low, mid, high)


# Example usage
arr = [4, 1, 7, 3, 8, 1]
merge_sort(arr, 0, len(arr) - 1)
print(arr)  # Output: [1, 1, 3, 4, 7, 8]
