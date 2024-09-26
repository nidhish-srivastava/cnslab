#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int arr_size;
    printf("Enter the number of elements: ");
    scanf("%d", &arr_size);

    int arr[arr_size];
    srand(time(0));
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % 100; // Random numbers between 0 and 99
    }

    printf("Employee id's are \n");
    printArray(arr, arr_size);

    clock_t start, end;
    start = clock();
    quickSort(arr, 0, arr_size - 1);
    end = clock();

    printf("\nEmployee id's in sorted order are \n");
    printArray(arr, arr_size);

    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to sort the array: %f seconds\n", time_taken);

    return 0;
}
