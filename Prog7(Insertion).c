#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform insertion sort
void insertionSort(long long arr[], int n) {
    for (int i = 1; i < n; i++) {
        long long key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    
    // Take input for the number of phone numbers
    printf("Enter the number of phone numbers: ");
    scanf("%d", &n);

    long long phoneNumbers[n];

    // Seed the random number generator
    srand(time(0));

    // Generate random phone numbers
    for (int i = 0; i < n; i++) {
        phoneNumbers[i] = 9000000000 + rand() % 1000000000; // Generate random phone number in range [9000000000, 9999999999]
    }

    // Display the generated phone numbers
    printf("Generated phone numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%lld\n", phoneNumbers[i]);
    }

    // Measure the time taken to sort
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    insertionSort(phoneNumbers, n);
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Display the sorted phone numbers
    printf("\nSorted phone numbers:\n");
    for (int i = 0; i < n; i++) {
        printf("%lld\n", phoneNumbers[i]);
    }

    // Display the time taken to sort
    printf("\nTime taken to sort the phone numbers: %f seconds\n", cpu_time_used);

    return 0;
}
