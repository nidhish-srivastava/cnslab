#include <stdio.h>

// Function to perform binary search
int binarySearch(int array[], int size, int key) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the key is present at mid
        if (array[mid] == key) {
            return mid;
        }
        // If key is greater, ignore the left half
        else if (array[mid] < key) {
            low = mid + 1;
        }
        // If key is smaller, ignore the right half
        else {
            high = mid - 1;
        }
    }

    // If the key is not present in the array
    return -1;
}

int main() {
    int size, key, result;

    // Taking input for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int array[size];

    // Taking input for the elements of the array
    printf("Enter %d elements in sorted order:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    // Taking input for the element to be searched
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Performing binary search
    result = binarySearch(array, size, key);

    if (result != -1) {
        printf("Element is present at index %d\n", result);
    } else {
        printf("Element is not present in the array\n");
    }

    return 0;
}
