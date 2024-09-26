#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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
    mergeSort(arr, 0, arr_size - 1);
    end = clock();

    printf("\nEmployee id's in sorted order are \n");
    printArray(arr, arr_size);

    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("\nTime taken to sort the array: %f seconds\n", time_taken);

    return 0;
}
