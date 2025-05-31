#include <stdio.h>
#include <math.h>  // for pow()
#include <conio.h>

// Function for Binary Search: O(log n)
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Function for Merge Sort-like example: O(n log n)
void mergeSortExample(int n) {
    int step = 1, i;
    while (step < n) {
        for (i = 0; i < n; i += 2 * step) {
            printf("Merging from %d to %d\n", i, i + 2 * step - 1); // Simulates merging step
        }
        step *= 2;  // log n steps
    }
}

// Function for Recursive Fibonacci: O(2^n)
int recursiveFibonacci(int n) {
    if (n <= 1)
        return n;
    return recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

int main() {
    int i, j, n = 5;
    int array[5] = {1, 2, 3, 4, 5};

    printf("\n O(1) - Constant Time\n");
    // Accessing each element: fixed number of steps regardless of size
    for (i = 0; i < 5; i++) {
        printf(" %d ", array[i]); // O(5) ? O(1)
    }

    printf("\n\n O(n^2) - Quadratic Time\n");
    // Nested loop: each runs n times, total operations = n * n
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("(%d,%d) ", i, j); // O(n^2)
        }
        printf("\n");
    }

    printf("\n O(log n) - Logarithmic Time\n");
    // Binary search simulation
    int sortedArr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int index = binarySearch(sortedArr, 8, 7);
    printf("7 found at index: %d\n", index); // O(log n)

    printf("\n O(n log n) - Linearithmic Time\n");
    // Merge sort simulation: log n levels, each doing n work
    mergeSortExample(8); // O(n log n)

    printf("\n O(2^n) - Exponential Time\n");
    // Recursive Fibonacci: 2^n complexity
    int fibTerm = 5;
    int fibResult = recursiveFibonacci(fibTerm);
    printf("Fibonacci(%d) = %d\n", fibTerm, fibResult); // O(2^n)

    return 0;
}

