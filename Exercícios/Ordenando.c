#include <stdio.h>

#define SIZE 10

void bubbleSort(int arr[], int n, int *swapCount) {
    int i, j, temp;
    *swapCount = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swapCount)++;
            }
        }
    }
}

void insertionSort(int arr[], int n, int *swapCount) {
    int i, key, j;
    *swapCount = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*swapCount)++;
        }
        arr[j + 1] = key;
        if (j + 1 != i) (*swapCount)++;
    }
}

void selectionSort(int arr[], int n, int *swapCount) {
    int i, j, minIdx, temp;
    *swapCount = 0;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
            (*swapCount)++;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int heights[SIZE] = {170, 165, 180, 175, 160, 155, 185, 190, 150, 160};
    int swapCount;

    printf("Vetor original:\n");
    printArray(heights, SIZE);

    // Bubble Sort
    int bubbleHeights[SIZE];
    for (int i = 0; i < SIZE; i++) bubbleHeights[i] = heights[i];
    bubbleSort(bubbleHeights, SIZE, &swapCount);
    printf("Bubble Sort:\n");
    printArray(bubbleHeights, SIZE);
    printf("Número de trocas: %d\n\n", swapCount);

    // Insertion Sort
    int insertionHeights[SIZE];
    for (int i = 0; i < SIZE; i++) insertionHeights[i] = heights[i];
    insertionSort(insertionHeights, SIZE, &swapCount);
    printf("Insertion Sort:\n");
    printArray(insertionHeights, SIZE);
    printf("Número de trocas: %d\n\n", swapCount);

    // Selection Sort
    int selectionHeights[SIZE];
    for (int i = 0; i < SIZE; i++) selectionHeights[i] = heights[i];
    selectionSort(selectionHeights, SIZE, &swapCount);
    printf("Selection Sort:\n");
    printArray(selectionHeights, SIZE);
    printf("Número de trocas: %d\n", swapCount);

    return 0;
}

