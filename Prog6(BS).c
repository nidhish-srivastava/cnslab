#include <stdio.h>
#include <stdlib.h>  // Include this header for srand and rand
#include <time.h>

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

    // Seed the random number generator
    srand(time(0));

    // Fill the array with random numbers
    printf("Randomly generated array:\n");
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;  // Generate random numbers in the range 0 to 99
        printf("%d ", array[i]);
    }
    printf("\n");

    // Taking input for the element to be searched
    printf("Enter the element to search: ");
    scanf("%d", &key);

    clock_t start, end;
    double cpu_time_used;

    start = clock();
    // Performing binary search
    result = binarySearch(array, size, key);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    if (result != -1) {
        printf("Element is present at index %d\n", result);
    } else {
        printf("Element is not present in the array\n");
    }

    printf("\nTime taken to search the element: %f seconds\n", cpu_time_used);
    return 0;
}
